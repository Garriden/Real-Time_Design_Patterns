//
// Created by garridom on 14/1/2020.
//

#ifndef INC_24_EVENT_H
#define INC_24_EVENT_H

class Event {
public:
    enum class Type {WARNING, CAUTION, ADVISORY, UNKNOWN};

    Event();
    explicit Event(Type t);
    ~Event();
    Type type() const;
    const char* typeAsString() const;
private:
    Type type_ = Type::UNKNOWN;
};


#endif //INC_24_EVENT_H
