#include<string>
#include<iostream>
#include<fstream>
#include<vector>

int main(int argc, char** argv){
    if(argc != 2){std::cerr<<"Error: Incorrect Number Of Arguments!"<<std::endl;return 1;}
    std::ifstream file(argv[1]);
    if(!file.is_open()){std::cout<<"Error: File ["<<argv[1]<<"] Not Found!"<<std::endl;}
    std::vector<std::string>* front_stack = new std::vector<std::string>();    
    std::vector<std::string>* back_stack = new std::vector<std::string>();

    std::string line;

    while(std::getline((std::istream&)file, line)){ 
        if(line.front() == '>'){
            front_stack->push_back(line.substr(1));
        }
        else if(line.front() == '<'){
            front_stack->pop_back();
        }
        else if(line.front() == '_'){
            if(line[1] == '>'){
                back_stack->push_back(line.substr(2));
            }
            else if(line[1] == '<'){
                back_stack->push_back(line.substr(2));
            }
        }
        else{
            std::string front_comp;
            for(std::string str : *front_stack){
                front_comp.append(str);
            }
            std::string back_comp;
            for(std::string str : *back_stack){
                back_comp.append(str);
            }
            std::system(
                (
                    front_comp + line + back_comp
                ).c_str()
            );
        }
    }

    file.close();
    delete front_stack;
}