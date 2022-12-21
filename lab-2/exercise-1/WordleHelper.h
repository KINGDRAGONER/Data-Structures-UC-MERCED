#ifndef WORDLE_HELPER_H
#define WORDLE_HELPER_H

#include <iterator>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class WordleHelper{
 
    std::vector<std::string> allowed;
    std::vector<std::string> answers;

    std::vector<std::string> green;
    std::vector<std::string> yellow;
    std::vector<std::string> gray;


    bool contains(std::string word, char c){
        for (int i = 0; i < word.length(); i++){
            if (word[i] == c){
                return true;
            }
        }

        return false;
    }

public:
    WordleHelper(){
        std::string answersFile = "answers.txt";
        std::string allowedFile = "allowed.txt";

        std::fstream newfile;

        newfile.open(answersFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                answers.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + answersFile + ".");
        }

        newfile.open(allowedFile, std::ios::in);
        if (newfile.is_open()){
            std::string tp;
            
            while(getline(newfile, tp)){
                allowed.push_back(tp);
            }
            newfile.close();
        }
        else {
            throw std::logic_error("Cant read file " + allowedFile + ".");
        }
    }

    void addGreen(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Green feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Green feedback must contain only lowercase letters or underscores");
        }

        green.push_back(feedback);
    }

    void addYellow(std::string feedback){
        if (feedback.size() != 5){
            throw std::logic_error("Yellow feedback must be exactly 5 characters");
        }
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c != '_' && (c < 'a' || c > 'z');
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters or underscores");
        }

        yellow.push_back(feedback);
    }

    void addGray(std::string feedback){
        if (std::any_of(feedback.begin(), feedback.end(), [](char c){
            return c < 'a' && c > 'z';
        })){
            throw std::logic_error("Yellow feedback must contain only lowercase letters");
        }

        gray.push_back(feedback);
    }
   /* int poslet (std:: string str1)
    {
        std:: string str2 = str1;
        int index = 0;
        for (int i =0; i< str2.length();i++)
        {
            if(str2[i]!= '-')
            {
                index = str2.find(i);
                return index;
            }
        }

    } */
    std::vector<std::string>possibleSolutions()
    {
      std::vector<std::string> sols = {};
      std::vector<std::string> fsols = {};

      std::vector<std::string> ols = {};
      std::vector<std::string> nsols = {};
      for (std::string words :answers) { 

        bool isgood = true;

        for (int s = 0; s < gray[0].length(); s++) 
        {
           
            if (contains(words, gray[0][s]))
            {
                isgood = false;
                break;
            }
        }
        if (isgood == true) {
          nsols.push_back(words);
        }  
        
       }
        for(std::string word: nsols)
        {
            bool isgood = false;
            for(int i =0; i< yellow[0].length();i++)
            {
                if(contains(word, yellow[0][i])&&word.find(yellow[0][i])!=yellow[0].find(yellow[0][i])&&yellow[0][i]!='_')
                    {
                        isgood = true;
                        break;
                    }
            }
            if(isgood)
            {
                ols.push_back(word);
            } 

        }
        for(std::string word: ols)
        {

            bool isgood = true;
            for(int i =0; i< green[0].length();i++)
            {

                if(word[i]!=green[0][i]/*&& word.find(green[0][i])!=green[0].find(green[0][i])*/&&green[0][i]!='_')
                    {
                        isgood = false;
                        break;
                    }
            }
                if(isgood)
                {
                  sols.push_back(word);
                } 

        }
        return sols;
    }

    std::vector<std::string> suggest(){
        // Optionally, your code here...
        return {"bring", "words", "close"};
    }

    ~WordleHelper(){

    }

    friend struct WordleTester;

};

#endif