#include <Arduino.h>
                    int pins[12]= {2,3,4,5,6,7,8,9,10,11,12,13}; 

                    void setup() {
                        for(int i = 0; 12>i; i++){
                            pinMode(pins[i],OUTPUT); 
                        }
                    }

                    void loop() {
                        
                    }
