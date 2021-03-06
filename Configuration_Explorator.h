#ifndef __EXPLORATOR_CONFIGURATION_H__
#define __EXPLORATOR_CONFIGURATION_H__

///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// H-Bridge Motors  ///////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

/////////////////// for the bell bot which should not use any of the H-bridge motors
#if HV_MAJOR == 0
#define NUM_MOTORS            0

#define MOT1_ACTIVE           false
#define MOT1_DIR_PIN          26
#define MOT1_PWM_PIN          25
#define MOT1_EN_PIN           28
#define MOT1_FAULT_PIN        27

#define MOT2_ACTIVE           false
#define MOT2_DIR_PIN          29
#define MOT2_PWM_PIN          32
#define MOT2_EN_PIN           31
#define MOT2_FAULT_PIN        30

#define MOT3_ACTIVE           false
#define MOT3_DIR_PIN          21
#define MOT3_PWM_PIN          20
#define MOT3_EN_PIN           2
#define MOT3_FAULT_PIN        22

// the direction of the motors, if one is spinning in the wrong way then change this value
#define M1_POLARITY           false
#define M2_POLARITY           false
#define M3_POLARITY           false

// this value can be used to determine how long and how fast to spin each motor...
#define M1_GEAR_RATIO         1
#define M2_GEAR_RATIO         1
#define M3_GEAR_RATIO         1

const bool active_motors[3] = {MOT1_ACTIVE, MOT2_ACTIVE, MOT3_ACTIVE};

///////////////////////// for the woodpecker bot
#elif HV_MAJOR == 1
#define NUM_MOTORS            3

#define MOT1_ACTIVE           true
#define MOT1_DIR_PIN          26
#define MOT1_PWM_PIN          25
#define MOT1_EN_PIN           28
#define MOT1_FAULT_PIN        27

#define MOT2_ACTIVE           false
#define MOT2_DIR_PIN          29
#define MOT2_PWM_PIN          32
#define MOT2_EN_PIN           31
#define MOT2_FAULT_PIN        30

#define MOT3_ACTIVE           false
#define MOT3_DIR_PIN          21
#define MOT3_PWM_PIN          20
#define MOT3_EN_PIN           2
#define MOT3_FAULT_PIN        22

// the direction of the motors, if one is spinning in the wrong way then change this value
#define M1_POLARITY           false
#define M2_POLARITY           false
#define M3_POLARITY           false

// this value can be used to determine how long and how fast to spin each motor...
#define M1_GEAR_RATIO         1
#define M2_GEAR_RATIO         67
#define M3_GEAR_RATIO         1

const bool active_motors[NUM_MOTORS] = {MOT1_ACTIVE, MOT2_ACTIVE, MOT3_ACTIVE};

#endif // HV_MAJOR

/*
void testMotor(int w, unsigned int len) {
  motors[w].enableDrivers();
  Serial.println();//"------------------------------");
  Serial.print("Starting Motor Test\n");
  motors[w].setM1Speed(50);
  Serial.print(" 50\t");
  delay(len / 14);
  motors[w].setM1Speed(150);
  Serial.print(" 150\t");
  delay(len / 3.5);
  motors[w].setM1Speed(50);
  Serial.print(" 50\t");
  delay(len / 7);
  // motor.setM1Speed(0);
  // Serial.print(" 0");
  // delay(len / 7);
  motors[w].setM1Speed(-50);
  Serial.print(" -50\t");
  delay(len / 7);
  motors[w].setM1Speed(-250);
  Serial.print(" -250\t");
  delay(len / 3.5);
  motors[w].setM1Speed(-50);
  Serial.print(" -50\t");
  delay(len / 14);
  Serial.print(" 0");
  motors[w].setM1Speed(0);
  motors[w].disableDrivers();
  Serial.println("\nFinished Motor Test");
  Serial.println();//"----------------------------");
}
*/

///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////// Solenoid Actuators /////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
// this is how long in MS to wait after the dampener is removed before striking with solenoid
#define DAMPENER_DELAY 10

/////////////////////////////// For the Bell Bot //////////////////////////////////////
#if HV_MAJOR == 0
#define NUM_SOLENOIDS 6
#define SOL1_PIN 12
#define SOL2_PIN 11
#define SOL3_PIN 7
#define SOL4_PIN 6
#define SOL5_PIN 4
#define SOL6_PIN 3

#elif HV_MAJOR == 1 
#define NUM_SOLENOIDS 9
#define SOL1_PIN 3
#define SOL2_PIN 4
#define SOL3_PIN 6
#define SOL4_PIN 12
#define SOL5_PIN 11
#define SOL6_PIN 14
#define SOL7_PIN 15
#define SOL8_PIN 16
#define SOL9_PIN 7
#endif

#if BODY_TYPE == BELL_BODY
#define SOL1_ACTIVE true
#define SOL2_ACTIVE true
#define SOL3_ACTIVE true
#define SOL4_ACTIVE true
#define SOL5_ACTIVE true
#define SOL6_ACTIVE true

#elif BODY_TYPE == WOODPECKER_BODY
// todo these need to be chosen by the body not the HV
#define SOL1_ACTIVE true
#define SOL2_ACTIVE false
#define SOL3_ACTIVE false
#define SOL4_ACTIVE false
#define SOL5_ACTIVE false
#define SOL6_ACTIVE false
#define SOL7_ACTIVE false
#define SOL8_ACTIVE false
#define SOL9_ACTIVE false
#endif // HV_MAJOR == 1

#if NUM_SOLENOIDS == 9
const int s_pins[] = {SOL1_PIN, SOL2_PIN, SOL3_PIN, SOL4_PIN, SOL5_PIN, SOL6_PIN, SOL7_PIN, SOL8_PIN, SOL9_PIN};
uint16_t sol_on_time[] = {30, 30, 30, 30, 30, 30, 30, 30, 30};
bool sol_state[] = {false, false, false, false, false, false, false, false, false}; // is the solenoid on or off
bool sol_active[] = {SOL1_ACTIVE, SOL2_ACTIVE, SOL3_ACTIVE, SOL4_ACTIVE, SOL5_ACTIVE, SOL6_ACTIVE, SOL7_ACTIVE, SOL8_ACTIVE, SOL9_ACTIVE};
const uint8_t num_active_solenoids = SOL1_ACTIVE + SOL2_ACTIVE + SOL3_ACTIVE + SOL4_ACTIVE + SOL5_ACTIVE + SOL6_ACTIVE + SOL7_ACTIVE + SOL8_ACTIVE + SOL9_ACTIVE;
unsigned long sol_timers[9];
elapsedMillis last_sol_action[9];

// the max and min values for the solenoids corrisponds to the lowest value which
// results in an audible sounds from the actuator
// the max is the value which produces the loudest sonic event from the solenoid
// any values higher than the max will not produce a louder sound
// These values should be tested and set within this file once determined in-situ
// between is the min time allowed between actuations for that solenoid
#define S1_MIN                24
#define S1_MAX                100
#define S1_BETWEEN            20

#define S2_MIN                10
#define S2_MAX                100
#define S2_BETWEEN            20

#define S3_MIN                10
#define S3_MAX                100
#define S3_BETWEEN            20

#define S4_MIN                10
#define S4_MAX                100
#define S4_BETWEEN            20

#define S5_MIN                10
#define S5_MAX                100
#define S5_BETWEEN            20

#define S6_MIN                10
#define S6_MAX                100
#define S6_BETWEEN            20

#define S7_MIN                10
#define S7_MAX                100
#define S7_BETWEEN            20

#define S8_MIN                10
#define S8_MAX                100
#define S8_BETWEEN            20

#define S9_MIN                10
#define S9_MAX                100
#define S9_BETWEEN            20

const int sol_min[9] = {S1_MIN, S2_MIN, S3_MIN, S4_MIN, S5_MIN, S6_MIN, S7_MIN, S8_MIN, S9_MIN};
const int sol_max[9] = {S1_MAX, S2_MAX, S3_MAX, S4_MAX, S5_MAX, S6_MAX, S7_MAX, S8_MAX, S9_MAX};

#elif NUM_SOLENOIDS == 6
const int s_pins[] = {SOL1_PIN, SOL2_PIN, SOL3_PIN, SOL4_PIN, SOL5_PIN, SOL6_PIN};
uint16_t sol_on_time[] = {30, 30, 30, 30, 30, 30};
bool sol_state[] = {false, false, false, false, false, false}; // is the solenoid on or off
bool sol_active[] = {true, true, true, true, true, true}; // is the solenoid on or off
const uint8_t num_active_solenoids = SOL1_ACTIVE + SOL2_ACTIVE + SOL3_ACTIVE + SOL4_ACTIVE + SOL5_ACTIVE + SOL6_ACTIVE;
unsigned long sol_timers[6];
elapsedMillis last_sol_action[6];

// the max and min values for the solenoids corrisponds to the lowest value which
// results in an audible sounds from the actuator
// the max is the value which produces the loudest sonic event from the solenoid
// any values higher than the max will not produce a louder sound
// These values should be tested and set within this file once determined in-situ

#define S1_MIN                10
#define S1_MAX                100
#define S2_MIN                10
#define S2_MAX                100
#define S3_MIN                10
#define S3_MAX                100
#define S4_MIN                10
#define S4_MAX                100
#define S5_MIN                10
#define S5_MAX                100
#define S6_MIN                10
#define S6_MAX                100

const int sol_min[6] = {S1_MIN, S2_MIN, S3_MIN, S4_MIN, S5_MIN, S6_MIN};
const int sol_max[6] = {S1_MAX, S2_MAX, S3_MAX, S4_MAX, S5_MAX, S6_MAX};
#endif


// TODO - something about grouping together the solenoids?
// to keep track of if the different solenoid outputs are active or not

//////////////////////////// Global Actuation Settings and Values ////////////////////

// time in ms in which the solenoids need to cool down between individual actuations
#define SOL_COOLDOWN 20

// This value is used to calculate how long between unit actuations
uint32_t ACTUATION_DELAY = 0;
elapsedMillis last_playback_tmr;


//////////////////////////////// Global Variables /////////////////////////
double color_feature_min = 1.00;
double color_feature_max = 0.0;

elapsedMillis feature_reset_tmr;
elapsedMillis last_led_update_tmr;
const unsigned long led_refresh_rate = 33; // for 30 updates a second
const unsigned long feature_reset_time = (1000 * 2.5);// every 2.5 minute?

double brightness_feature_min = 1.0;
double brightness_feature_max = 0.0;

double current_brightness = 1.0;
double last_brightness = 1.0;

double current_color = 0.5;
double last_color = 0.5;

double last_feature;
double current_feature;

// for mapping the target color to real colors
#define RED_LOW                 0
#define RED_HIGH                50

#define GREEN_LOW               150
#define GREEN_HIGH              50

#define BLUE_LOW                55
#define BLUE_HIGH               255

#define NUM_NEOP_MANAGERS       3

#define SPLIT_BAND              10
// options are SPECTRAL_CENTROID or SPLIT_BAND
#define COLOR_FEATURE          SPLIT_BAND

double peak_val = 0.0;
double last_peak = 0.0;

///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// Rhythm detection stuff ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// the maximum number of rhythms to store
#define MAX_RHYTHMS 10
// the maximum number of notes which can be stored in a single rhythm
#define MAX_NOTES 24

uint8_t active_rhythm; // what rhythm number is to be played next
uint8_t active_notes; // what note number from within the current rhythm will be played next

elapsedMillis last_onset; // when was the last onset detected?
elapsedMillis last_vocalisation; // how long it has been since the bot vocalised last

unsigned long min_inter_note_rhythm = 100; // the shortest amount of time between onsets
unsigned long max_inter_note_rhythm = 1000; // the longest amount of time between onsets

void detectOnset() {
  // given the current audio features determine if an onset has occured
}

#define AUDIO_MEMORY 60

elapsedMillis last_audio_usage_print;
#define AUDIO_USAGE_POLL_RATE 5000

bool but_test[4];
float pot_test[4];

float ACTIVITY_LEVEL = 0.0;
float MOTOR_MOVEMENT = 0.0;
float STRIKE_LENGTH  = 30.0;

#endif // __CONFIGURATION__H__
