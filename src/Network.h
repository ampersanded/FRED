/*
  This file is part of the FRED system.

  Copyright (c) 2010-2015, University of Pittsburgh, John Grefenstette,
  Shawn Brown, Roni Rosenfield, Alona Fyshe, David Galloway, Nathan
  Stone, Jay DePasse, Anuroop Sriram, and Donald Burke.

  Licensed under the BSD 3-Clause license.  See the file "LICENSE" for
  more information.
*/

//
//
// File: Network.h
//

#ifndef _FRED_NETWORK_H
#define _FRED_NETWORK_H

#include "Place.h"


/**
 * This class represents an activity network in the FRED application. It
 * inherits from <code>Place</code>.  The class contains static
 * variables that will be filled with values from the parameter file.
 *
 * @see Place
 */
class Network: public Place {
public: 

  Network() {}

  ~Network() {}

  Network( const char *lab, fred::place_subtype _subtype, fred::geo lon, fred::geo lat);

  static void get_parameters();

  int get_group(int disease, Person * per) {
    return 0;
  }

  int get_container_size() {
    return get_size();
  }

  double get_transmission_prob(int disease, Person * i, Person * s);

  double get_contacts_per_day(int disease);

  bool should_be_open(int day, int disease) {
    return true;
  }

  void print();

private:
  static double contacts_per_day;
  static double** prob_transmission_per_contact;
};

#endif // _FRED_NETWORK_H
