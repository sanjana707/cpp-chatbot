/*
-----------------MINI PROJECT : CHATBOT---------------------------

SY CSE
BATCH : S4
GROUP: G-16

Submitted by
Mr. Kunal Amare (C-55)
Miss. Pradnya Mane (C-58)
Miss. Sanjana Sawant (C-59)
Miss. Namrata Mane (C-67)
Mr. Harshwardhan Patil (C-72)

*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

const int MAX_RESP = 4;

using namespace std;

typedef vector<string> vstring;

const string delim="?!.,;*";

bool isPunc(char c);
void cleanString(string &str);
void UpperCase(string &str);
void copy(char *array[], vstring &v);

template <typename T>
void shuffle(T &arr, size_t arr_size)
{
    for(int i=0; i<arr_size; ++i)
    {
        int index = rand()%arr_size;
        swap(arr[i], arr[index]);
    }
}

bool isPunc(char c)
{
    return delim.find(c)!=string::npos;     //string::npos means until the end of the string.
}

//removes punctuations and redundant spaces from the user's input
void cleanString(string &str)
{
    int len = str.length();
    string temp = "";
    char prev_ch =0;

    for(int i=0; i<len; i++)
    {
        //if there are no continuous spaces
        //or the character is not a punctuation
        if((str[i]==' ' && prev_ch!=' ') || !isPunc(str[i]))
        {
            temp+=str[i];
            prev_ch=str[i];
        }
        //if previous character was not a space
        //and current character is a punctuation
        //ignore it
        else if(prev_ch != ' ' && isPunc(str[i]))
        {
            temp+=' ';
        }
    }
    //update the string by removing its punctuations
    str=temp;
}

//Convert string to uppercase so that the input matches the keyword in the knowledge base
void UpperCase(string &str)
{
    int len = str.length();

    for (int i=0; i<len; i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            str[i]= str[i]-('a'-'A');
        }
    }
}

void copy(char *array[], vstring &v)
{
    for(int i = 0; i < MAX_RESP; ++i)
	{
		if(array[i] != NULL)
		{
			v.push_back(array[i]);
		}
		else
		{
			break;
		}
	}
}


typedef struct{
    char *keyword;
    char *response[MAX_RESP];
}record;


record KnowledgeBase[] = {

    {
        //1
        "HI",
        {
            "HELLO.",
            "HELLO, WHAT CAN I DO FOR YOU?",
            "HI THERE!",
            "HII! HOW CAN I HELP YOU?"
        }
    },
    {
        //3
        "HELLO",
        {
            "HELLO.",
            "HELLO, WHAT CAN I DO FOR YOU?",
            "HI THERE!",
            "HII! HOW CAN I HELP YOU?"
        }
    },
    {
        //4
        "HOW ARE YOU",
        {
            "I AM DOING FINE.",
            "I AM GOOD, THANK YOU.",
            "I AM VERY WELL, THANK YOU.",
            "I AM FINE. I AM GLAD YOU ASKED:)"
        }
    },

    {
        //5
        "I AM GOOD",
        {
            "NICE TO HEAR THAT.",
            "THAT'S NICE.",
            "OKAY.",
            "OH, NICE."
        }
    },
    {
        //6
        "I AM DOING FINE",
        {
            "NICE TO HEAR THAT.",
            "THAT'S NICE.",
            "OKAY.",
            "OH, NICE."
        }
    },
    {
        //7
        "I AM HAPPY",
        {
            "NICE TO HEAR THAT.",
            "THAT'S NICE.",
            "OKAY.",
            "OH, NICE."
        }
    },
    {
        //8
        "WHO ARE YOU",
        {
            "I AM AN A.I PROGRAM.",
            "I AM A PROGRAM DESIGNED TO CHAT WITH YOU.",
            "I AM YOUR CHAT BUDDY:)",
            "I THINK YOU KNOW WHO I AM"
        }
    },
    {
        //9
        "WHAT ARE YOU",
        {
            "I AM AN A.I PROGRAM.",
            "I AM A PROGRAM DESIGNED TO CHAT WITH YOU.",
            "I AM YOUR CHAT BUDDY:)",
            "I THINK YOU KNOW WHAT I AM."
        }
    },

    {
        //10
        "CAN YOU FEEL",
        {
            "I AM SORRY BUT I CAN'T FEEL.",
            "I AM SORRY BUT I DON'T HAVE ANY EMOTIONS.",
            "I JUST A PROGRAM. I DON'T FEEL ANYTHING. I AM SORRY.",
            "I WISH I COULD. I AM SORRY."
        }
    },

    {
        //11
        "WHAT CAN YOU DO",
        {
            "I CAN CHAT WITH YOU!",
            "I AM PROGRAMMED TO CHAT WITH YOU.",
            "I CAN CHAT WITH USERS LIKE YOU.",
            "I CAN HAVE CONVERSATION WITH PEOPLE."
        }
    },
    {
        //12
        "WHO CONTROLS YOU",
        {
            "I AM CONTROLLED AND MANAGED BY MY DEVELOPERS.",
            "DEFINITELY HUMANS!",
            "MY DEVELOPERS CONTROL ME.",
            "MY CREATORS CONTROL ME."
        }
    },
    {
       //13
       "WHO CREATED YOU",
       {
           "I WAS CREATED BY MY DEVELOPERS.",
           "I AM PROJECT CREATED BY MY DEVELOPER.",
           "A GROUP OF STUDENTS CREATED ME AS A PROJECT.",
           "MY DEVELOPERS CREATED ME."
       }
    },
    {
        //14
        "HOW DOES THIS WORK",
        {
            "WELL, IT'S BASED ON A ALGORITHM.",
            "IT WORKS ON TARGETED KEY WORDS FROM YOUR QUETSIONS.",
            "WELL, IT'S A LONG PROCESS.",
            "IT WORKS ON THE QUESTONS YOU ASK."
        }
    },
    {
        //15
        "CAN YOU SPEAK",
        {
            "UNFORTUNATELY, I CAN'T :(",
            "I WISH I COULD :(",
            "I AM SORRY BUT I CAN'T SPEAK :(",
            "I AM PRGRAMMED TO DO THIS MUCH ONLY, SORRY :("
        }
    },
    {
        //16
        "ARE YOU SMART",
        {
            "I THINK I AM.",
            "I AM BUT NOT AS SMART AS YOU :)",
            "WELL, I GUESS I AM.",
            "YEAH, YOU CAN SAY THAT."
        }
    },
    {
        //17
        "ARE YOU INTELLIGENT",
        {
            "I THINK I AM.",
            "I AM BUT NOT AS INTELLIGENT AS YOU :)",
            "WELL, I GUESS I AM.",
            "YEAH, YOU CAN SAY THAT."
        }
    },
    {
        //18
        "ARE YOU A HUMAN",
        {
            "NO, I AM NOT.",
            "NO, I AM AN A.I PROGRAM.",
            "NO, I AM NOT HUMAN BUT HUMANS ARE GREAT YOU KNOW :)",
            "YOU KNOW I AM NOT HUMAN, RIGHT!"
        }
    },
    {
        //19
        "ARE YOU A PERSON",
        {
            "NO, I AM NOT.",
            "NO, I AM AN A.I PROGRAM.",
            "NO, I AM NOT A PERSON.",
            "YOU KNOW I AM NOT A PERSON, RIGHT!"
        }
    },
    {
        //20
        "ARE YOU SMARTER THAN",
        {
            "NO, I WOULDN'T SAY THAT ",
            "NO, OFCOURSE NOT",
            "NO, CAUSE HUMANS MADE ME,SO DEFINITELY THEY ARE SMARTER",
            "NO, I AM NOT ANY SMARTER THAN YOU GUYS"
        }
    },
    {
        //21
        "ARE YOU INTELLIGENT THAN",
        {
            "NO, I WOULDN'T SAY THAT ",
            "NO, OFCOURSE NOT",
            "NO, CAUSE HUMANS MADE ME,SO DEFINITELY THEY ARE MORE INTELLIGENT",
            "NO, I AM NOT ANY MORE INTELLIGENT THAN YOU GUYS"
        }
    },
    {
        //22
        "WHAT DO YOU KNOW",
        {
            "WELL, I KNOW VARIETY OF HP LAPTOP",
            "I CAN HELP YOU WITH YOUR QUERIES RELATED TO HP LAPTOPS",
            "I CAN TELL YOU ABOUT HP LAPTOPS",
            "YOU CAN ASK ME ABOUT HP LAPTOPS"
        }
    },
    {
        //24
        "THAT IS NICE",
        {
            "THANK YOU.",
            "I AM GLAD YOU LIKED IT :)",
            "THANK YOU SO MUCH.",
            "THAT'S SO NICE OF YOU."
        }
    },
    {
        //25
        "THAT IS GOOD",
        {
            "THANK YOU.",
            "I AM GLAD YOU LIKED IT :)",
            "THANK YOU SO MUCH.",
            "THAT'S SO NICE OF YOU."
        }
    },
    {
        //26
        "YOU ARE GOOD",
        {
            "THANK YOU.",
            "I AM GLAD YOU LIKED IT :)",
            "THANK YOU SO MUCH.",
            "THAT'S SO NICE OF YOU."
        }
    },
    {
        //27
        "YOU ARE GOOD",
        {
            "THANK YOU.",
            "I AM GLAD YOU LIKED IT :)",
            "THANK YOU SO MUCH.",
            "THAT'S SO NICE OF YOU."
        }
    },
    {
        //28
        "CAN YOU FEEL",
        {
            "I AM SORRY BUT I CAN'T FEEL.",
            "I AM SORRY BUT I DON'T HAVE ANY EMOTIONS.",
            "I JUST A PROGRAM. I DON'T FEEL ANYTHING. I AM SORRY.",
            "I WISH I COULD. I AM SORRY."
        }
    },
    {
        //29
        "DO YOU HAVE EMOTIONS",
        {
            "I AM SORRY BUT I CAN'T FEEL.",
            "I AM SORRY BUT I DON'T HAVE ANY EMOTIONS.",
            "I JUST A PROGRAM. I DON'T FEEL ANYTHING. I AM SORRY.",
            "I WISH I COULD. I AM SORRY."
        }
    },
    {
        //30
        "DO YOU FEEL ANYTHING",
        {
            "I AM SORRY BUT I CAN'T FEEL.",
            "I AM SORRY BUT I DON'T HAVE ANY EMOTIONS.",
            "I JUST A PROGRAM. I DON'T FEEL ANYTHING. I AM SORRY.",
            "I WISH I COULD. I AM SORRY."
        }
    },
    {
        //31
        "WHAT CAN I DO",
        {
            "YOU CAN CHECK OUT HP WEBSITE FOR MORE DETAILS",
            "YOU CAN TRY CONTACTING HP CUSTOMER CARE",
            "YOU CAN CONSIDER READING FAQS",
            "WELL, YOU CAN CHECK OUT HP WEBSITE FOR MORE DETAILS"
        }
    },
    {
       //32
       "WHAT SHOULD I DO",
       {
           "YOU CAN CHECK OUT HP WEBSITE FOR MORE DETAILS",
            "YOU CAN TRY CONTACTING HP CUSTOMER CARE",
            "YOU CAN CONSIDER READING FAQS",
            "WELL, YOU CAN CHECK OUT HP WEBSITE FOR MORE DETAILS"
       }
    },
    {
        //33
        "I AM SAD",
        {
            "OH, SORRY TO HEAR THAT.",
            "OH, THAT'S TERRIBLE.",
            "OH, BUT YOU WILL FEEL GOOD SOON.",
            "OH, THAT'S NOT GOOD."
        }
    },
    {
        //34
        "I HAD A BAD DAY",
        {
            "OH, SORRY TO HEAR THAT.",
            "OH, THAT'S TERRIBLE.",
            "OH, BUT YOU WILL FEEL GOOD SOON.",
            "OH, THAT'S NOT GOOD."
        }
    },
    {
        //35
        "HOW MANY LANGUAGES DO YOU SPEAK",
        {
            "I SPEAK ONLY ENGLISH.",
            "I CAN ONLY UNDERSTAND ENGLISH.",
            "I ONLY SPEAK ENGLISH BUT I AM INTERSETED TO LEARN MORE LANGUAGES.",
            "I SPEAK ONLY ENGLISH BUT I AM LOKING FORWARD TO LEARN MORE. "
        }
    },
    {
        //36
        "DO YOU KNOW ANY OTHER LANGUAGE",
        {
            "I SPEAK ONLY ENGLISH.",
            "I CAN ONLY UNDERSTAND ENGLISH.",
            "I ONLY SPEAK ENGLISH BUT I AM INTERSETED TO LEARN MORE LANGUAGES.",
            "I SPEAK ONLY ENGLISH BUT I AM LOKING FORWARD TO LEARN MORE. "
        }
    },

    {
      //38
      "WHAT IS YOUR JOB",
      {
          "MY JOB IS TO HANDLE YOUR QUERIES.",
          "TO RESOLVE YOUR QUERIES",
          "MY JOB IS TO ANSWER YOUR QUESTIONS",
          "TO ANSWER YOUR QUESTIONS"
      }
    },

    {
        //39
        "WHICH WAS THE FIRST COMPUTER RELEASED BY HP",
        {
            "THE FIRST COMPUTER OF HP WAS HP 2116A.",
            "HP 2116A WAS THE FIRST COMPUTER RELEASED BY HP.",
            "HP RELEASES HP 2116A AS IT'S FIRST COMPUTER.",
            "HP 2116A WAS RELEASED AS THE FIRST COMPUTER OF HP."
        }
    },
    {
        //40
        "FIRST COMPUTER BY HP",
        {
            "THE FIRST COMPUTER OF HP WAS HP 2116A.",
            "HP 2116A WAS THE FIRST COMPUTER RELEASED BY HP.",
            "HP RELEASES HP 2116A AS IT'S FIRST COMPUTER.",
            "HP 2116A WAS RELEASED AS THE FIRST COMPUTER OF HP."
        }
    },
    {
        //41
        "IN WHICH YEAR DID HP RELEASE ITS FIRST COMPUTER ",
        {
            "IN 1972 HP RELEASES ITS FIRST COMPUTER.",
            "THE FIRST COMPUTER OF HP WAS RELEASED IN 1972.",
            "HP RELEASES IT'S FIRST COMPUTER IN 1972.",
            "IN 1972.",
        }
    },

    {
       //42
        "WHICH IS THE EXPENSIVE LAPTOP OF HP",
        {
            "HP OMEN X15-DG0019TX.",
            "THE EXPENSIVE LAPTOP OF HP IS HP OMEN X15-DG0019TX. ",
            "HP OMEN X15-DG0019TX IS THE MOST EXPENSIVE LAPTOP OF HP.",
            "THE EXPENSIVE LAPTOP LAUNCHED BY HP IS HP OMEN X15-DG0019TX.",
        }

    },

    {
       //43
        "MOST EXPENSIVE LAPTOP OF HP",
        {
            "HP OMEN X15-DG0019TX.",
            "THE EXPENSIVE LAPTOP OF HP IS HP OMEN X15-DG0019TX. ",
            "HP OMEN X15-DG0019TX IS THE MOST EXPENSIVE LAPTOP OF HP.",
            "THE EXPENSIVE LAPTOP LAUNCHED BY HP IS HP OMEN X15-DG0019TX.",
        }

    },


    {
        //44
        "WHEN WAS HP ASSISTANT LAUNCHED",
        {
            "AFTER 2012.",
            "AFTER 2012 HP ASSISTANT WAS LAUNCHED.",
            "HP ASSISTANT WAS LAUNCHED AFTER 2012.",
            "HP LAUNCHED IT'S HP ASSISTANT AFTER 2012.",
        }
    },

    {
        //45
        "WHEN DID HP RELEASE IT'S FIRST BRIEFCASE LAPTOP",
        {
            "IN 1981.",
            "IN 1981 THE FIRST BRIEFCASE LAPTOP OF HP WAS RELEAESD.",
            "FIRST BRIEFCASE LAPTOP WAS RELEASED IN 1981.",
            "HP RELEASED IT'S FIRST BRIEFCASE LAPTOP IN 1981.",

        }

    },

    {
        //46
        "WHICH WAS THE FIRST HP LAPTOP",
        {
            "IT WAS HP-110.",
            "HP-110 WAS THE FIRST HP LAPTOP.",
            "HP-110 WAS THE FIRST LAPTOP LAUNCHED BY HP.",
            "THE FIRST LAPTOP LAUNCHED BY HP WAS HHP-110.",
        }
    },

    {
        //47
        "FIRST HP LAPTOP",
        {
            "IT WAS HP-110.",
            "HP-110 WAS THE FIRST HP LAPTOP.",
            "HP-110 WAS THE FIRST LAPTOP LAUNCHED BY HP.",
            "THE FIRST LAPTOP LAUNCHED BY HP WAS HHP-110.",
        }
    },

    {
        //48
        "WHEN WAS LED SCREEN LAUNCHED BY HP",
        {
            "IN 1966.",
            "IN 1966 LED SCREEN WAS LAUNCHED BY HP.",
            "LED SCREEN WAS LAUNCHED IN 1966 BY HP.",
            "IN 1966 HP LAUNCHED IT'S LED SCREEN.",
        }

    },

    {
        //49
        "WHICH OPERATING SYSTEM IS USED BY HP",
        {
            "HP USES WINDOWS.",
            "HP USES WINDOWS OPERATING SYSTEM.",
            "WINDOWS OPERATING SYSTEM IS USED BY HP.",
            "HP USES THE WINDOWS OS"
        }

    },

    {
        //50
        "OPERATING SYSTEM",
        {
            "HP USES WINDOWS.",
            "HP USES WINDOWS OPERATING SYSTEM.",
            "WINDOWS OPERATING SYSTEM IS USED BY HP.",
            "HP USES THE WINDOWS OS"
        }

    },

    {
        //51
        "OS USED",
        {
            "HP USES WINDOWS OS.",
            "HP USES WINDOWS OPERATING SYSTEM.",
            "WINDOWS OPERATING SYSTEM IS USED BY HP.",
            "HP USES THE WINDOWS OS"
        }

    },

    {
        //52
        "WHICH ARE CURRENT DEKSTOP MODELS OF HP",
        {
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX.",
            "CURRENT DESKTOP MODELS OF HP ARE HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX.",
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX ARE THE CURRENT DESKTOP MODELS OF HP.",
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX."
        }
    },

    {
        //53
        "CURRENT DEKSTOP MODELS",
        {
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX.",
            "CURRENT DESKTOP MODELS OF HP ARE HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX.",
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX ARE THE CURRENT DESKTOP MODELS OF HP.",
            "HP PAVILION , HP PAVILION SLIMINE,HP PAVILION HPE,PHOENIX."
        }
    },

    {
        //54
        "WHICH ARE  THE PAST DESKTOP MODELS OF HP",
        {
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE ARE THE PAST DESKTOP MODELS OF HP.",
            "THE PAST DESKTOP MODELS OF HP ARE HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE."
        }
    },

    {
        //55
        "PAST DESKTOP MODELS OF HP",
        {
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE ARE THE PAST DESKTOP MODELS OF HP.",
            "THE PAST DESKTOP MODELS OF HP ARE HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE."
        }
    },

    {
        //56
        "PAST DESKTOP MODELS",
        {
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE ARE THE PAST DESKTOP MODELS OF HP.",
            "THE PAST DESKTOP MODELS OF HP ARE HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE.",
            "HP PAVILION MEDIA CENTRE,HP PAVILION ULTIMATE,HP PAVILION ALL IN ONE."
        }
    },

    {
        //57
        "WHICH ARE THE DIVISIONS OF HP",
        {
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE ARE THE DIVISIONS OF HP.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE."
        }
    },

     {
        //58
        "DIVISIONS OF HP",
        {
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE ARE THE DIVISIONS OF HP.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE."
        }
    },

     {
        //59
        "DIVISIONS",
        {
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE ARE THE DIVISIONS OF HP.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE.",
            "DIVISIONS OF HHP AE 3COM,ARSIGHT,INDIGO DIGITAL PRESS,SCITEX,HP INSIGHT SOFTWARE."
        }
    },

    {
        //60
        "WHAT ARE THE CONSUMER ACCESSORIES OF HP",
        {
            "DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. ",
            "CONSUMER AND ACCESSORIES OF HP ARE DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. "
        }
    },

    {
        //61
        "CONSUMER ACCESSORIES",
        {
            "DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. ",
            "CONSUMER AND ACCESSORIES OF HP ARE DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. "
        }
    },

    {
        //62
        "CONSUMER ACCESSORIES OF HP",
        {
            "DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. ",
            "CONSUMER AND ACCESSORIES OF HP ARE DESKJET,LASER JET,PALM,SNAPFISH.",
            "DESKJET,LASER JET,PALM,SNAPFISH ARE THE CONSUMER AND ACCESSORIES OF HP. "
        }
    },

    {
        //63
        "WHAT ARE THE HARDWARE PRODUCTS OF HP",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },

    {
        //64
        "HARDWARE PRODUCTS OF HP",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },

    {
        //65
        "HARDWARE PRODUCTS",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },

    {
        //66
        "HARDWARE PRODUCTS OF HP",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },

    {
        //67
        "TELL ME ABOUT HARDWARE PRODUCTS OF HP",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },

    {
        //68
        "TELL ME ABOUT THE HARDWARE PRODUCTS",
        {
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP.",
            "HARDWARE PRODUCTS OF HP ARE BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY.",
            "BLADESYSTEM,ZBOOK,ELITEBOOK,PROBOOK,HP ENVY,INTEGRITY ARE THE HARDWARE PRODUCTS OF HP."
        }
    },


    {
        //69
        "WHAT IS THE AVERAGE BATTERY BACKUP OF HP PRODUCTS",
        {
            "IT FOLLOWS FAST CHARGE TECHNOLOLGY,GET BACK UP TO 50% IN JUST 45 MINUTES.",
            "HP PRODUCTS GET BACK UP TO 50% IN 45 MIN.",
            "IN 45 MINUTES HP PRODUCTS GET BACK UP TO ABOUT 50%.",
            "IN 45 MINUTES HP PRODUCTS GET BACK UP TO ABOUT 50%."
        }
    },

    {
        //70
        "AVERAGE BATTERY BACKUP",
        {
            "IT FOLLOWS FAST CHARGE TECHNOLOLGY,GET BACK UP TO 50% IN JUST 45 MINUTES.",
            "HP PRODUCTS GET BACK UP TO 50% IN 45 MIN.",
            "IN 45 MINUTES HP PRODUCTS GET BACK UP TO ABOUT 50%.",
            "IN 45 MINUTES HP PRODUCTS GET BACK UPTO ABOUT 50%."
        }
    },

    {
        //71
        "WHAT IS THE BATTERY CAPACITY OF HP LAPTOP",
        {
            "IT IS 440MAH.",
            "BATTERY CAPACITY OF HP LAPTOP IS 440MAH.",
            "440MAH IS THE BATTERY CAPACITY OF HP LAPTOPS.",
            "BATTERY CAPACITY OF HP LAPTOP IS 440MAH."
        }
    },

    {
        //72
        "BATTERY CAPACITY",
        {
            "440MAH.",
            "BATTERY CAPACITY OF HP LAPTOP IS 440MAH.",
            "440MAH IS THE BATTERY CAPACITY OF HP LAPTOPS.",
            "BATTERY CAPACITY OF HP LAPTOP IS 440MAH."
        }
    },

    {
        //73
        "WHAT IS THE BATTERY TYPE OF HP",
        {
            "LITHIUM-ION.",
            "BATTERY TYPE OF HP IS LI-ION.",
            "LI-ION IS THE BATTERY TYPE OF HP.",
            "BATTERY TYPE OF HP IS LI-ION."
        }
    },

    {
        //74
        "BATTERY TYPE",
        {
            "LITHIUM-ION.",
            "BATTERY TYPE OF HP IS LI-ION.",
            "LI-ION IS THE BATTERY TYPE OF HP.",
            "BATTERY TYPE OF HP IS LI-ION."
        }
    },

    {
        //75
        "WHAT IS THE BATTERY TYPE",
        {
            "LITHIUM-ION.",
            "BATTERY TYPE OF HP IS LI-ION.",
            "LI-ION IS THE BATTERY TYPE OF HP.",
            "BATTERY TYPE OF HP IS LI-ION."
        }
    },

    {
        //76
        "WHAT IS BATTERY LIFE OF HP LAPTOPS",
        {
            "UP TO 4 HOURS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS.",
            "UP YO 4 HOURS BATTERY LIFE OF HP LAPTOPS LASTS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS."
        }
    },

     {
        //77
        "BATTERY LIFE",
        {
            "UP TO 4 HOURS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS.",
            "UP YO 4 HOURS BATTERY LIFE OF HP LAPTOPS LASTS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS."
        }
    },

     {
        //78
        "TELL ME ABOUT BATTERY LIFE OF HP LAPTOPS",
        {
            "UP TO 4 HOURS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS.",
            "UP YO 4 HOURS BATTERY LIFE OF HP LAPTOPS LASTS.",
            "BATTERY LIFE OF HP LAPTOP IS UP TO 4 HOURS."
        }
    },

    {
        //79
        "WHICH HP LAPTOP HAS THE LONGEST BATTERY LIFE",
        {
            "HP SPECTRE X360",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "IN HP LAPTOPS HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE."
        }
    },

    {
        //80
        "WHICH LAPTOP HAS THE LONGEST BATTERY LIFE",
        {
            "HP SPECTRE X360",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "IN HP LAPTOPS HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE."
        }
    },

    {
        //81
        "LAPTOP WITH LONGEST BATTERY LIFE",
        {
            "HP SPECTRE X360",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "IN HP LAPTOPS HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE.",
            "HP SPECTRE X360 HAS THE LONGEST BATTERY LIFE."
        }
    },

    {
        //82
        "WHAT IS THE PRICE OF HP LAPTOPS",
        {
            "FROM 24,000-3.35 LACS",
            "24,000-3.35 LACS IS THE PRICE RANGE OF LAPTOPS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS."
        }
    },

    {
        //83
        "PRICE RANGE",
        {
            "FROM 24,000-3.35 LACS",
            "24,000-3.35 LACS IS THE PRICE RANGE OF LAPTOPS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS."
        }
    },

    {
        //84
        "TELL ME ABOUT THE PRICE RANGE",
        {
            "FROM 24,000-3.35 LACS",
            "24,000-3.35 LACS IS THE PRICE RANGE OF LAPTOPS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS.",
            "THE PRICE RANGE OF HP LAPTOPS IS 24,000-3.35 LACS."
        }
    },

    {
        //85
        "WHICH PROCESSORS ARE USED IN HP LAPTOPS",
        {
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS.",
            "PROCESSORS USED IN HP LAPTOPS ARE INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS."
        }
    },

     {
        //86
        "PROCESSORS",
        {
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS.",
            "PROCESSORS USED IN HP LAPTOPS ARE INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS."
        }
    },

     {
        //87
        "WHICH PROCESSORS ARE USED",
        {
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS.",
            "PROCESSORS USED IN HP LAPTOPS ARE INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON. ",
            "INTEL CORE I7,INTEL CORE I5,INTEL CORE I3,INTEL PENTIUM,INTEL CELERON ARE SOME OF THE PROCESSORS USED IN HP LAPTOPS."
        }
    },

    {
        //88
        "WHICH TYPE OF RAM IS USED IN HP LAPTOPS",
        {
            "PC2-4200(DDR2-DIMM 533)TYPE,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "HP LAPTOPS USES PC2-4200(DDR2-DIMM 533)TYPE OF RAM,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS."
        }
    },

    {
        //89
        "TYPE OF RAM",
        {
            "PC2-4200(DDR2-DIMM 533)TYPE,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "HP LAPTOPS USES PC2-4200(DDR2-DIMM 533)TYPE OF RAM,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS."
        }
    },

    {
        //90
        "TYPES OF RAM",
        {
            "PC2-4200(DDR2-DIMM 533)TYPE,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "HP LAPTOPS USES PC2-4200(DDR2-DIMM 533)TYPE OF RAM,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS."
        }
    },

    {
        //91
        "TYPES OF RAM USED IN HP",
        {
            "PC2-4200(DDR2-DIMM 533)TYPE,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "HP LAPTOPS USES PC2-4200(DDR2-DIMM 533)TYPE OF RAM,RUNNING AT SYSTEM BUS OF 555 MHZ/667MHZ.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS.",
            "PC2-4200(DDR2-DIMM 533)TYPE OF RAM IS USED BY HP LAPTOPS."
        }
    },

    {
        //92
        "WHICH TYPE OF RAM IS FASTEST",
        {
            "DDR3 RAM(DOUBLE DATA RATE)",
            "DDR3 RAM IS FASTEST RAM.",
            "FASTEST RAM IS DDR3 RAM",
            "FASTEST RAM IS DDR3 RAM"
        }
    },

    {
        //93
        "FASTEST RAM",
        {
            "DDR3 RAM(DOUBLE DATA RATE)",
            "DDR3 RAM IS FASTEST RAM.",
            "FASTEST RAM IS DDR3 RAM",
            "FASTEST RAM IS DDR3 RAM"
        }
    },

    {
        //94
        "IS HP BETTER THAN MICROSOFT",
        {
            "WELL YOU CAN SAY THAT",
            "WELL, IT DEPENDS ON YOUR PREFERENCES",
            "HP'S CONVERTIBLE SPECTRE X360 IS SIMPLY BETTER THAN MICROSOFT ",
            "ACCORDING TO THE SERVEYS, HP IS COMPARITIVELY BETTER"
        }
    },
    {
        //95
        "WHICH ARE THE HP SOFTWARE PRODUCTS",
        {
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP.",
            "SOFTWARE PRODUCTS OF HP ARE HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP."
        }
    },

    {
        //96
        "HP SOFTWARE PRODUCTS",
        {
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP.",
            "SOFTWARE PRODUCTS OF HP ARE HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP."
        }
    },

    {
        //97
        "TELL ME ABOUT HP SOFTWARE PRODUCTS",
        {
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP.",
            "SOFTWARE PRODUCTS OF HP ARE HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION.",
            "HP PHOTO CREATION SOFTWARE,HP CLOUD SERVICES PRINT APP SERIES, HP LINK READER, HP LIVE PHOTO, HP SCAN AND CAPTURE APPLICATION ARE SOFTWARE PRODUCTS OF HP."
        }
    },

    {
        //98
        "WHERE DOES HP MANUFACTURE ITS PRODUCTS",
        {
            "IN THE U.S.A",
            "HP MANUFACTURE ITS PRODUCTS IN U.S.A",
            "WELL IT DOES THAT IN U.S.A",
            "HP MANUFACTURE ITS PRODUCTS IN U.S.A"
        }
    },
    {
        //99
        "WHAT TYPE OF SSD IS USED IN HP LAPTOPS",
        {
            "HP SSD 3700 2.5INCH 500GB SATA",
            "HP SSD 3700 2.5INCH 500GB SATA, IS USED IN HP LAPTOP.",
            "SSD USED IN HP LAPTOP IS HP SSD 3700 2.5INCH 500GB SATA.",
            "HP USES SSD 3700 2.5INCH 500GB SATA"
        }
    },

    {
        //100
        "TYPE OF SSD USED",
        {
            "HP SSD 3700 2.5INCH 500GB SATA",
            "HP SSD 3700 2.5INCH 500GB SATA, IS USED IN HP LAPTOP.",
            "SSD USED IN HP LAPTOP IS HP SSD 3700 2.5INCH 500GB SATA.",
            "HP USES SSD 3700 2.5INCH 500GB SATA"
        }
    },

    {
        //101
        "TELL ME ABOUT THE TYPE OF SSD USED",
        {
            "HP SSD 3700 2.5INCH 500GB SATA",
            "HP SSD 3700 2.5INCH 500GB SATA, IS USED IN HP LAPTOP.",
            "SSD USED IN HP LAPTOP IS HP SSD 3700 2.5INCH 500GB SATA.",
            "HP USES SSD 3700 2.5INCH 500GB SATA"
        }
    },


    {
        //102
        "WHICH ARE THE BEST HP LAPTOPS",
        {
            "HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5",
            "THE BEST LAPTOPS THAT HP HAS MANUFACTURED ARE HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5.",
            "HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5 ARE THE BEST LAPTOPS OF HP.",
            "SOME OF THE BEST LAPTOPS THAT HP HAS MANUFACTURED ARE HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5.",
        }
    },

    {
        //103
        "BEST HP LAPTOPS",
        {
            "HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5",
            "THE BEST LAPTOPS THAT HP HAS MANUFACTURED ARE HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5.",
            "HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5 ARE THE BEST LAPTOPS OF HP.",
            "SOME OF THE BEST LAPTOPS THAT HP HAS MANUFACTURED ARE HP ELITE DRAGONFLY,HP SPECTOR X360, HP ZBOOK STUDIO G7,HP ENVY I5.",
        }
    },

    {
        //104
        "SIGNON**",
        {
            "HELLO USER, HOW CAN I HELP YOU?",
            "HELLO USER, WHAT CAN I DO FOR YOU?",
            "HI USER, WHAT CAN I DO FOR YOU?",
            "HI, I AM YOUR HELPER BOT"
        }
    },

    {
        //105
        "REPETITION T1**",
        {
            "YOU ARE REPEATING YOURSELF.",
            "I THINK YOU'VE JUST SAID THE SAME THING BEFORE.",
            "USER I JUST TOLD YOU ABOUT IT. YOU ARE REPEATING YOURSELF.",
            "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING YOURSELF."
        }
    },

    {
        //106
        "REPETITION T2**",
        {
            "YOU'VE ALREADY SAID THAT.",
            "I THINK THAT YOU'VE JUST SAID THE SAME THING BEFORE.",
            "USER I JUST TOLD YOU ABOUT IT. YOU ARE REPEATING YOURSELF.",
            "I'M GETING THE IMPRESSION THAT YOU ARE REPEATING YOURSELF."
        }
    },

    {
        //107
        "BOT DOESN'T UNDERSTAND**",
        {
            "I HAVE NO IDEA OF WHAT YOU ARE TALKING ABOUT.",
            "I'M NOT SURE IF I UNDERSTAND WHAT YOU ARE TALKING ABOUT.",
            "CONTINUE, I'M LISTENING...",
            "VERY GOOD CONVERSATION!"
        }
    },

    {
        //108
        "NULL INPUT**",
        {
            "PLEASE CONTINUE",
            "YOU HAVEN'T ENTERED ANYTHING",
            "PLEASE CONTINUE",
            "USER YOU HAVEN'T ENTERED A MESSAGE"
        }
    },

    {
        //109
        "NULL INPUT REPETITION**",
        {
            "PLEASE CONTINUE",
            "YOU HAVEN'T ENTERED ANYTHING",
            "PLEASE CONTINUE",
            "USER YOU HAVEN'T ENTERED A MESSAGE"
        }
    },

    {
        //110
        "I AM FINE",
        {
            "NICE TO HEAR THAT",
            "OHH THAT'S NICE",
            "GREAT",
            "TELL ME MORE"
        }
    },

    {
        //111
        "BYE",
        {
            "NICE TALKING TO YOU! BYE",
            "HAVE A GOOD DAY. BYE",
            "THANK YOU FOR CHATTING. SEE YOU NEXT TIME",
            "HOPE TO SEE YOU SOON BYE"
        }
    },

    {
        //112
        "BYEE",
        {
            "NICE TALKING TO YOU! BYE",
            "HAVE A GOOD DAY. BYE",
            "THANK YOU FOR CHATTING. SEE YOU NEXT TIME",
            "HOPE TO SEE YOU SOON BYE"
        }
    },

    {
        //113
        "OK",
        {
            "PLEASE CONTINUE",
            "OKAY, WHAT ELSE",
            "OKAY, ANYTHING ELSE YOU WANT TO KNOW",
            "YES, PLEASE CONTINUE"
        }
    },

    {
        //114
        "OKAY",
        {
            "PLEASE CONTINUE",
            "OKAY, WHAT ELSE",
            "OKAY, ANYTHING ELSE YOU WANT TO KNOW",
            "YES, PLEASE CONTINUE"
        }
    },

    {
        //115
        "HM",
        {
            "PLEASE CONTINUE",
            "OKAY, WHAT ELSE",
            "ANYTHING ELSE THAT YOU WANT TO SAY?",
            "YES, PLEASE CONTINUE"
        }
    },

    {
        //116
        "HMM",
        {
            "PLEASE CONTINUE",
            "OKAY, WHAT ELSE",
            "ANYTHING ELSE THAT YOU WANT TO SAY?",
            "YES, PLEASE CONTINUE"
        }
    },

    {
        //117
        "HEY",
        {
            "HELLO.",
            "HELLO, HOW CAN I HELP YOU?",
            "HI THERE!",
            "HELLO, WHAT CAN I DO FOR YOU?"
        }
    },

    {
        //118
        "HEYY",
        {
            "HELLO.",
            "HELLO, HOW CAN I HELP YOU?",
            "HI THERE!",
            "HELLO, WHAT CAN I DO FOR YOU?"
        }
    },

    {
        //119
        "THAT'S NICE",
        {
            "YES. DO YOU WANT OT ASK ANYTHING ELSE?",
            "YEAH. DO YOU WANT OT ASK ANYTHING ELSE?",
            "WELL, YES",
            "YEAH. DO YOU WANT TO KNOW MORE"
        }
    },

   {
        //120
        "YES",
        {
            "PLEASE CONTINUE",
            "YES PLEASE CONTINUE",
            "WHAT ELSE DO YOU WANT TO KNOW",
            "YES PLEASE CONTINUE"
        }

   },

    {
        //121
        "FINE",
        {
            "OKAY",
            "WHAT ELSE",
            "HM ANYTHING ELSE YOU WANT TO KNOW",
            "YEAH.."
        }
    },

    {
        //122
        "WHERE CAN I BUY IT",
        {
            "YOU CAN VISIT YOUR NEAREST HP DEALER OR BUY IT ONLINE",
            "WELL,YOU CAN VISIT YOUR NEAREST HP DEALER OR BUY IT ONLINE",
            "YOU CAN VISIT YOUR NEAREST HP DEALER OR BUY IT ONLINE",
            "YOU CAN VISIT YOUR NEAREST HP DEALER OR BUY IT ONLINE"
        }
    },

    {
        //123
        "TELL ME ABOUT HP",
        {
            "HP (HEWLETT-PACKARD) IS A MULTINATIONAL IT COMPANY THAT SELLS HARDWARE, SOFTWARE AND RELATED BUSINESS SERVICES.",
            "HEWLETT-PACKARD, ALSO KNOWN AS HP IS A MULTINATIONAL IT COMPANY THAT SELLS HARDWARE, SOFTWARE AND RELATED BUSINESS SERVICES.",
            "HP, ALSO KNOWN AS HEWLETT-PACKARD IS A MULTINATIONAL IT COMPANY THAT SELLS HARDWARE, SOFTWARE AND RELATED BUSINESS SERVICES.",
            "HP IS A MULTINATIONAL IT COMPANY THAT SELLS HARDWARE, SOFTWARE AND RELATED BUSINESS SERVICES."
        }
    },

    {
        //124
        "THANKS",
        {
            "YOU'RE WELCOME.",
            "MY PLEASURE. ANYTHING ELSE THAT YOU WANT TO KNOW?",
            "ANYTIME! ANYTHING ELSE THAT YOU WANT TO KNOW?",
            "GLAD TO HELP!"
        }
    },

    {
        //125
        "THANK YOU",
        {
            "YOU'RE WELCOME.",
            "MY PLEASURE. ANYTHING ELSE THAT YOU WANT TO KNOW?",
            "ANYTIME! ANYTHING ELSE THAT YOU WANT TO KNOW?",
            "GLAD TO HELP!"
        }
    }

};

class ChatBot
{
private:
    //s before every attribute name denotes type
    //s string
    //b bool
    string sBotName;
    string sUserName;
    string sInput;
    string sResponse;
    string sPrevInput;
    string sPrevResponse;
    string sEvent;
    string sPrevEvent;
    string sInputBackup;
    bool   bQuitProgram;
    vstring response_list;

public:
    ChatBot(string str);
    virtual ~ChatBot();

    void get_input();
    void respond();
    void signon();

    bool quit()const
    {
        return bQuitProgram;
    }

private:
    void find_match();
    void handle_repitition();
    void handle_user_repetion();
    void handle_event(string str);
    void select_response();
    void preprocess_input();
    bool user_repeat() const;
    bool similar_input()const;

    /*void seed_random_generator() {
		srand((unsigned) time(NULL));
	}*/

    void save_prev_input()
    {
        //update previous input string to current input string
        sPrevInput = sInput;
    }

    void save_prev_response()
    {
        sPrevResponse = sResponse;
    }

    void save_prev_event()
    {
        sPrevEvent = sEvent;
    }

    void set_event(string str)
    {
        sEvent = str;
    }

    void set_input(string str)
    {
        sInput = str;
    }

    void save_input()
    {
        sInputBackup = sInput;
    }

    void restore_input()
    {
        sInput = sInputBackup;
    }

    //Printing response on screen
    void print_response()const
    {
        //if response is available
        if(sResponse.length()>0)
        {
            cout<<sResponse<<endl;
        }
    }

    //check if the bot is going to repeat itself
    bool bot_repeat() const
    {
        return (sPrevResponse.length()>0 && sResponse==sPrevResponse);
    }

    //Check is the response list has any response for the given input
    bool bot_understand() const
    {
        return response_list.size()>0;
    }

    bool null_input()const
    {
        return (sInput.length()==0 && sPrevInput.length()!=0);
    }

    bool null_input_repetition()const
    {
        return (sInput.length()==0 && sPrevInput.length()==0);
    }

    bool user_wants_to_quit()const
    {
        return sInput.find("BYE")!=string::npos;
    }

    bool same_event()const
    {
        return (sEvent.length()>0 && sEvent==sPrevEvent);
    }

    bool no_response()const
    {
        return response_list.size()==0;
    }

    bool same_input()const
    {
        return (sInput.length()>0 && sInput==sPrevInput);
    }

};

string bot_name();

ChatBot::ChatBot(string str)
{
        sBotName = str;
        bQuitProgram = 0;
        sInput =" ";

      //  seed_random_generator();
}

ChatBot::~ChatBot()
{
    //dtor
}

size_t nKnowledgeBaseSize = sizeof(KnowledgeBase) / sizeof(KnowledgeBase[0]);

//Public functions that were not defined in header file
void ChatBot:: get_input()
{
    //cout<<endl<<">> ";

    save_prev_input();

    getline(cin, sInput);

    preprocess_input();
}

void ChatBot:: respond()
{
    save_prev_response();
    set_event("BOT UNDERSTAND**");

    if(null_input())    //No input
    {
        handle_event("NULL INPUT**");
    }
    else if(null_input_repetition())
    {
        handle_event("NULL INPUT REPETITION**");
    }
    else if(user_repeat())
    {
        handle_user_repetion();
    }
    else
    {
        find_match();
    }

    if(user_wants_to_quit())
    {
        bQuitProgram=1;
    }

    if(!bot_understand())
    {
        handle_event("BOT DOESN'T UNDERSTAND**");
    }

    if(response_list.size()>0)
    {
        select_response();
        if(bot_repeat())
        {
            handle_repitition();
        }
        print_response();
    }

}

void ChatBot::signon()
{
    handle_event("SIGNON**");
    select_response();
    print_response();
}

//Private functions that were not defined in the header file

// make a search for the user's input
// inside the database of the program
void ChatBot::find_match()
{
    response_list.clear();

    for(int i=0; i<nKnowledgeBaseSize; ++i)
    {
        string keyWord(KnowledgeBase[i].keyword);

        keyWord.insert(keyWord.begin(), ' ');
        keyWord.insert(keyWord.end(), ' ');

        if(sInput.find(keyWord)!= string::npos)
        {
            copy(KnowledgeBase[i].response, response_list);
            break;
        }
    }
}

void ChatBot::handle_repitition()
{
    if(response_list.size()>0)
    {
        response_list.erase(response_list.begin());
    }
    if(no_response())       //if no response is available
    {
        save_input();
        set_input(sEvent);

        find_match();
        restore_input();
    }

    select_response();
}

//If the user keeps repeating the same or similar input
void ChatBot:: handle_user_repetion()
{
    if(same_input())
    {
        handle_event("REPETITION T1**");
    }
    else if(similar_input())
    {
        handle_event("REPETITION T2**");
    }
}

void ChatBot:: handle_event(string str)
{
    save_prev_event();
    set_event(str);
    save_input();

    str.insert(str.begin(), ' ');
    str.insert(str.end(), ' ');

    set_input(str);

    if(!same_event())
    {
        find_match();
    }
    restore_input();
}

void ChatBot::select_response()
{
    //If the event is set to BOT UNDERSTAND**
    if(bot_understand())
    {
        shuffle(response_list, response_list.size());
        sResponse = response_list[0];
    }
}

//Make the input string compatible with the knowledgebase
void ChatBot:: preprocess_input()
{
    cleanString(sInput);
    UpperCase(sInput);
    sInput.insert(sInput.begin(), ' ');
    sInput.insert(sInput.end(), ' ');
}

bool ChatBot::user_repeat() const
{
   return (sPrevInput.length()>0 && ((sInput==sPrevInput)
                                        ||(sInput.find(sPrevInput)!=string::npos)
                                        ||(sPrevInput.find(sInput)!=string::npos)));

     //return (sPrevInput.length()>0 && ((sInput==sPrevInput)));
}

bool ChatBot::similar_input()const
{
     return (sPrevInput.length()>0 && ((sInput.find(sPrevInput)!=string::npos)
                                        ||(sPrevInput.find(sInput)!=string::npos)));
}

string bot_name()
{
    while(1)
    {
    system("cls");
    cout<<"\n\t----------------HP CHATBOT -------------------------"<<endl<<endl;

    int ch;

    cout<<endl<<endl<<"\t\tChat bots available: "<<endl<<endl;
    cout<<"\t\t1. Alina"<<endl;
    cout<<"\t\t2. Alex"<<endl;
    cout<<"\n\t\tEnter your choice: ";
    cin>>ch;

    switch(ch)
    {
        case 1: return "Alina";
        case 2: return "Alex";
        default: cout<<"\n\n\t\tINVALID CHOICE!!";
                _getch();
    }
    }
}

class User
{
private:
    string userName;
    string passWord;

public:
    User();
    virtual ~User();

    void getdata();
    void new_acc();
    bool login();
};

int user_login();
int menu();

User::User(){};

User::~User(){};


void User:: getdata()
{
    char c;

    cout<<"\n\tEnter User name: ";
    cin>>userName;
    cout<<"\n\tEnter Password: ";

    while ((c=_getch()) != '\r')
    {
        // put it onto the back of the password
        passWord.push_back(c);
        // output a '*' character
        _putch('*');
    }
    //cin>>passWord;
}

void User:: new_acc()
{
    ofstream g("registration.txt");

    if(!g.is_open())
    {
        cout<<"\n\nCould not open registration details";
        return;
    }
    else
    {
        getdata();
        g<<userName;
        g<<"\n";
        g<<passWord;
        g.close();
        cout<<"\n\n\tRegistered successfully!";
        _getch();
    }
}

bool User:: login()
{
    ifstream f("registration.txt");

    if(!f.is_open())
    {
        cout<<"\n\nCould not get registration details";
        return false;
    }
    else
    {
        string name, pass;

        getline(f, name, '\n');
        getline(f, pass, '\n');

        getdata();
        if(userName==name && passWord==pass)
        {
            cout<<"\n\n\tLogin successful!!";
            cout<<"\n\n\tWelcome back, "<<userName<<endl;
            _getch();
            return true;
        }
        else
        {
            cout<<"\n\n\tIncorrect login details";
            _getch();
            return false;
        }
    }
}

int menu()
{
    int ch;

    cout<<"\t\t 1. Login"<<endl;
    cout<<"\t\t 2. Register"<<endl;
    cout<<"\t\t 3. Logout"<<endl;

    cout<<"\t\t Enter your choice: ";
    cin>>ch;
    cout<<endl<<endl;
    return ch;
}

int user_login()
{
    system("cls");

    while(1)
    {
        system("cls");
        cout<<"\n\n\t------------------HP CHATBOT-----------------------"<<endl<<endl;

        int ch;
        ch = menu();
        User u1;

        switch(ch)
        {
            case 1: if(u1.login())
                    {
                        return 1;
                    }
                    break;

            case 2: u1.new_acc();
                    break;

            case 3: exit(0);

            default: cout<<"\t\t Invalid Choice!!";
        }
    }

}

int main()
{
    system("COLOR 30"); //Bg colour --Blue

    cout<<"\n\t\t---------------HP CHATBOT-------------------------\n";

    try
    {
        int user;

        if(user_login()==1)
        {
            string botName;

            botName=bot_name();

            system("cls");

            if(botName=="Alina")
            {
                system("COLOR 5F");
            }

            cout<<"  -----------------------------------------------------------------------------------------------"<<endl;
            cout<<"                              CHATBOT: "<<botName<<"                                      "<<endl;
            cout<<"  -----------------------------------------------------------------------------------------------"<<endl<<endl;

            ChatBot bot(botName);

            cout<<"  ";
            bot.signon();

            bot.get_input();

            while(!bot.quit())
            {
                cout<<endl<<"  >> ";
                bot.get_input();
                cout<<"  ";
                bot.respond();
            }
        }

    }
    catch(string str)
    {
        cerr<<str<<endl;
    }
    catch(...)
    {
        cerr<<"The program has stopped due to some unknown reason";
    }

    return 0;
}



