#include <iostream>
#include <string>
#include <vector>

class Note{
private:
    std::string name;
public:
    Note(){
        this->name = "";
    }
    Note(std::string name){
        this->name = name;
    }
    std::string getName(){
        return this->name;
    }

    bool operator == (Note &a){
        return a.getName() == this->getName();
    }

};

class Scale{
private:
    std::vector<Note> notes;
    Note tune;

protected:
    const std::string errorTune = "Tune isn't valid";

public:
    // TODO getTune
    // TODO hasEightNotes
    // TODO hasTetraAchordes
    // TODO verifyDistance
    // TODO isScale
    Note getTune(std::vector<Note> notes){
        Note tune;
        try{
            tune = notes[0] == notes[notes.size()-1] ? Note(notes[0].getName()) : Note("error");
        } catch(tune.getName() == "error"){
            std::cout<<errorTune<<std::endl;
        }

        return tune;
    }
    Scale(std::vector<Note> notes){
        this->notes=notes;
    }
    std::vector<Note> getNotes(){
        return this->notes;
    }
};



int main()
{

}