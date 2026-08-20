#ifndef BSTAPP_HPP
#define BSTAPP_HPP

#include "BST.hpp"
#include <iostream> 
#include <string> 

namespace BSTSpace
{
  template<class K, class V>
  class Dictionary
  {
	  private:
	  BST<K,V> *data;//BST representation of data
	  
	  public:
	  Dictionary();
      ~Dictionary(); // Destructor to free the allocated BST
	  bool getValue(K key, V &value);//get the value corresponding to a key
	  void setValue(K key, V value);//set the value of a given key
	  void insert(K key, V value);//insert a key value pair
      void printAll(); // Added to display the whole dictionary
	  
  };
  
  template<class K, class V>
  Dictionary<K,V>::Dictionary()
  {
	  data = new BST<K,V>();
  }

  template<class K, class V>
  Dictionary<K,V>::~Dictionary()
  {
	  delete data;
  }
  
  template<class K,class V>
  bool Dictionary<K,V>::getValue(K key, V &value)
  {
	  return data->search(key, value);
  }
  
  template<class K,class V>
  void Dictionary<K,V>::setValue(K key, V value)
  {
	  data->insert(key, value);
  }
  
  template<class K, class V>
  void Dictionary<K,V>::insert(K key, V value)
  {
	  data->insert(key, value);
  }

  template<class K, class V>
  void Dictionary<K, V>::printAll()
  {
      std::cout << "Dictionary Contents: ";
      data->PrintTree();
  }
  
  void Demo()
  {
    
    Dictionary<int,std::string> StudentDict;
    std::string name;
    bool is_present;
    
    StudentDict.insert(8, "Ameya");
    StudentDict.insert(10, "Aami");
    StudentDict.insert(25,"Medha");
    StudentDict.insert(9,"Vishal");
    StudentDict.insert(5,"Amritha");
    StudentDict.insert(7,"Anjali"); 
    
    // Demonstrate updating a value
    std::cout << "Updating Roll 7..." << std::endl;
    StudentDict.setValue(7, "Anjali");
    
    is_present = StudentDict.getValue(7, name);
    std::cout << "Searching for Roll 7: ";
    if (is_present == true)
        std::cout << name << std::endl;
    else
        std::cout << "Roll Number not Present" << std::endl;

    is_present = StudentDict.getValue(99, name);
    std::cout << "Searching for Roll 99: ";
    if (is_present == true)
        std::cout << name << std::endl;
    else
        std::cout << "Roll Number not Present" << std::endl;

    // Print all key-value pairs in sorted order
    StudentDict.printAll();
  
  }

}
#endif