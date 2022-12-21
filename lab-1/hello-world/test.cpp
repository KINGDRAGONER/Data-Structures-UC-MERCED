#include <igloo/igloo.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace igloo;

std::string exec(std::string command) {
   char buffer[128];
   std::string result = "";

   // Open pipe to file
   FILE* pipe = popen((command + " 2>&1").c_str(), "r");
   if (!pipe) {
      return "popen failed!";
   }

   // read till end of process:
   while (!feof(pipe)) {

      // use buffer to read and add to result
      if (fgets(buffer, 128, pipe) != NULL)
         result += buffer;
   }

   pclose(pipe);
   result.erase(result.find_last_not_of(" \t\n\r\f\v") + 1);
   return result;
}

std::string compile_run(std::string filename){
    std::string compile = exec("g++ -I. -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("./temp");
        system("rm -f temp");
    }

    return output;
}

std::string compile_run(std::string filename, std::string input){
    std::string compile = exec("g++ -I. -o temp " + filename);
    std::string output = compile;
    if (compile == ""){
        output = exec("echo \"" + input + "\" | ./temp");
        system("rm -f temp");
    }

    return output;
}

Context(TestHelloWorld){
    Spec(TheOnlyTest){
        std::string result = compile_run("main.cpp");
        Assert::That(result, Equals("Hello World"));
    }
};

int main(int argc, const char* argv[]){
    TestRunner::RunAllTests(argc, argv);
}
