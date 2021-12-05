//file:object.hpp//
#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_
#include <iostream>
#include <fstream>
#include <string>
#include "params.hpp"

// class Object holds the data of the input objects-points of the dataset
// i.e. the coordinates in a d-vector and the object name, from input file

class Object 
{
private:
	std::string identifier; // the object identifier name, as read from input file
	float * vector;			// the coordinates of the d-dimensional point-object in an array

public:
	// default constructor creates a random normalized d-dimensional point-object, each coordinate follows normal(0,1) distribution 
	Object();
	// constructor through another d-dimensional input array
	Object(float input_vector[], std::string & object_name);
	// constructor through another d-dimensional input array with empty object name
	Object(float input_vector[]);
	~Object();
	// name identifier getter
	const std::string & get_name() const; 
	// calculates the inner-product of calling object with given object p (both d-dimensional)
	float inner_prod(const Object& p) const;
	// calculates the euclidean distance between caller object and argument object
	double euclidean_distance(const Object& p) const;
	// sets caller object's info to given arg object's info (does a copy basically)
	void set(const Object& p);
	// sets ith coordinate of Object to value
	void set_ith(int i, float value);
	// gets ith coordinate of Object
	float get_ith(int i) const;
	// print method for debugging
	void print() const;
	// write object to file
	void print(std::ofstream & file) const;

	//Same as with the above prints but now print only the coordinates of the object
	void print_coordinates() const;
	void print_coordinates(std::ofstream & file) const;
};

double euclidean(const Object & p, const Object & q);

#endif