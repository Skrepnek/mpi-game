/* 
 * File:   Action.cpp
 * Author: skrep
 * 
 * Created on 25 de Fevereiro de 2015, 19:37
 */

#include "Action.h"

Action::Action(){
    this->waitRandomTime();
}

Action::Action(long waitingTimeNSec){
    this->actionType = Action::WAIT;
    this->waitingTime = waitingTimeNSec;
}

Action::Action(const Action& orig) {
}

Action::~Action() {
}

void Action::waitRandomTime(){
    this->actionType = Action::WAIT;
    this->waitingTime = rand() % (MPIGameConfig::RANDOM_WAIT_TIME_SEC * Utils::NANOSECOND);
}

void Action::reduceWaitingTime(long time){
    if (this->waitingTime < time){
        this->waitingTime = 0;
    }
    else{
        this->waitingTime -= time;
    }
}

void Action::moveTo(Position* destination){
    this->actionType = Action::MOVETO;
    this->movement = new Movement(destination);
}

void Action::updatePositionAndFacing(Position *&currentPosition, Facing *&currentFacing, long time){
    this->movement->updatePositionAndFacing(currentPosition, currentFacing, time);
}

void Action::serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer){
    writer.StartObject();
    
    writer.String("actionType");
    writer.Int(this->actionType);
    writer.String("waitingTime");
    writer.Int64(this->waitingTime);
    
    
//    writer.String("movement");
//    writer.StartObject();
//    writer.String("currentState");
//    writer.Int(this->getMovement()->getCurrentState());
//    writer.EndObject();
    
    
    writer.EndObject();
}

void Action::deserialize(rapidjson::Document& document){
    rapidjson::Value& valueActionType = document["actionType"];
    rapidjson::Value& valueWaitingType = document["waitingTime"];
    rapidjson::Value::MemberIterator member = document.FindMember("movement");
    //member->
    this->actionType = valueActionType.GetInt();
    this->waitingTime = valueWaitingType.GetInt64();
}