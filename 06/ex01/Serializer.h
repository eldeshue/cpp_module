
#ifndef SERIALIZER_H
#define  SERIALIZER_H

typedef unsigned long uintptr_t;

class Data;
class Serializer
{
private:
	Serializer();
	Serializer(Serializer const&);
	~Serializer();
	Serializer& operator=(Serializer const&);

public:
	static uintptr_t Serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif
