#include <iostream>
using namespace std;

// Your end product 
class PlanetWeight{
    double _weight;
    double _bench;
    double _squat;
    double _deadlift;
    

public:
    PlanetWeight(double set_weight) { _weight = set_weight; }
    void setWeight(double set_weight) { _weight = set_weight; }
    void setBench(double set_bench) { _bench = set_bench; }
    void setSquat(double set_squat) { _squat = set_squat; }
    void setDeadlift(double set_deadlift) { _deadlift = set_deadlift;}

    double getWeight() {return _weight; }
    double getBench() { return _bench; }
    double getSquat() { return _squat; }
    double getDeadlift() { return _deadlift; }
    
    void show() {
    	cout << "Weight: " <<_weight << endl;
      cout << "Bench: " <<_bench << endl;
    	cout << "Squat: "<<_squat << endl;
      cout << "deadlift: "<<_deadlift << endl << endl;
    }
};

// PlanetBuilder Abstract Class all builders should have at least these methods
class PlanetBuilder{
protected:
    PlanetWeight *person_weight;
public:
    virtual void getPersonWeight() = 0;
    virtual void buildBench() = 0;
    virtual void buildSquat() = 0;
    virtual void buildDeadlift() = 0;
    PlanetWeight* getPlanetWeight(){ return person_weight; }
};

// PlanetBuilder concrete class knows only how to build PlanetWeight!
class earthBuilder: public PlanetBuilder{
public:
   void getPersonWeight() { cout << "Earth "; person_weight = new PlanetWeight(210); } 
   //
    void buildBench() { person_weight->setBench(225);   }

    void buildSquat() {  person_weight->setSquat(315);   }

    void buildDeadlift() {  person_weight->setDeadlift(375);   }

    
};

// PlanetBuilder concrete class knows only how to build  PlanetWeight
class moonBuilder: public PlanetBuilder {

public:

    void getPersonWeight() { person_weight = new PlanetWeight(34.8); }

    void buildBench() { person_weight->setBench(1360.34); }

    void buildSquat() { person_weight->setSquat(1904.47);   }

    void buildDeadlift() { person_weight->setDeadlift(2267.23);   }

    
};

// PlanetBuilder concrete class knows only how to build  PlanetWeight!
class marsBuilder: public PlanetBuilder {

public:

    void getPersonWeight() { person_weight = new PlanetWeight(78.96); }

    void buildBench() { person_weight->setBench(598.4);   }

    void buildSquat() { person_weight->setSquat(837.77);   }

    void buildDeadlift() { person_weight->setDeadlift(997.34);   }

    
};

// PlanetBuilder concrete class knows only how to build  PlanetWeight!
class sunBuilder: public PlanetBuilder {

public:

    void getPersonWeight() { person_weight = new PlanetWeight(5604); }

    void buildBench() { person_weight->setBench(8.03);   }

    void buildSquat() { person_weight->setSquat(11.24);   }

    void buildDeadlift() { person_weight->setDeadlift(13.38);   }

    
};



// Defines steps and tells to the builder that build in given order.
class Director{

    PlanetBuilder *builder;

public:

    PlanetWeight* createPersonweight(PlanetBuilder *builder) {
        builder->getPersonWeight();
        builder->buildSquat();
        builder->buildBench();
        builder->buildDeadlift();
        
        return builder->getPlanetWeight();
    }
};

int main() {
  //PlanetWeight* planet = new PlanetWeight();
  //cout << "What is your weight?:\n";
  //int w;
  //cin >> w;
  //planet->setWeight(w);
  
  
	
  Director dir;
  moonBuilder mb;
  earthBuilder eb;
  marsBuilder ab;
  sunBuilder sb;

  PlanetWeight *earth = dir.createPersonweight(&eb);
  
	PlanetWeight *moon = dir.createPersonweight(&mb);
  PlanetWeight *mars = dir.createPersonweight(&ab);
  PlanetWeight *sun = dir.createPersonweight(&sb);
	
	earth->show();
  delete earth;
  cout << "Moon ";
	moon->show();
  delete moon;
  cout << "Mars ";
  mars->show();
  delete mars;      
  cout << "Sun ";  
  sun->show();
  delete sun;

  
	return 0;
}