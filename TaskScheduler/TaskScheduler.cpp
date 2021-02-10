#include <iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
int entrytype=0;
void RandomEnter()
{
    srand(time(NULL));
   
    int WorkTime, Quant = 0;  
    const int CountTask = 20;
    int TaskTime[CountTask] = { 0 };
    int TaskPriority[CountTask] = { 0 };
    int EnterTaskTime[CountTask] = { 0 };
    int Count[CountTask] = { 0 }; 
    double middlePriority[CountTask] = { 0 };
    std::cout << "_________________________________________________________________________________________\n";
    std::cout << "Tasks    |";
    for (int i = 0; i < 20; i++)
    {
        Count[i] = i + 1;
        printf  ("%3d|", Count[i]);
    }
    std::cout << "\nTime     |";
    for (int i = 0; i < 20; i++)
    {
        TaskTime[i] = rand() % 19+1;
        printf("%3d|", TaskTime[i]);
    }
    std::cout << "\nPriority |";
    for (int i = 0; i < 20; i++)
    {
        TaskPriority[i] = rand() % 9+1;
        printf("%3d|", TaskPriority[i]);
    }
    std::cout << "\nLoginTime|";
    for (int i = 0; i < 20; i++)
    {
        EnterTaskTime[i] = rand() % 40;
        printf("%3d|", EnterTaskTime[i]);
    }
    std::cout << "\n_________________________________________________________________________________________|\n";
    WorkTime = rand() % 80 + 20;
    std::cout << "How much time? There is " << WorkTime << " left\n";
    int* s = new int[CountTask];
    for (int j = 0; j < CountTask; j++)
    {
        middlePriority[j] = double (TaskPriority[j])/ double(TaskTime[j]);
    }
    for (int j = 0; j < CountTask; j++) s[j] = 0;
    int sum = 0;
    int i = 1;
    while (Quant < WorkTime)
    {
        double mpr = 0;
        int PriorityMax = 0;
        int ChoosedMax = 0;
        int TimeMax = 0;
        for (int j = 0;j < CountTask;j++)
          
                if ((middlePriority[j] > PriorityMax) && (s[j] != 1) && (Quant + TaskTime[j] <= WorkTime))
                {
                    mpr = middlePriority[j];
                    ChoosedMax = Count[j];
                    TimeMax = TaskTime[j];
                    PriorityMax = TaskPriority[j];
                }
            


        if (ChoosedMax == 0 && PriorityMax == 0 && TimeMax == 0)
            {
                std::cout << "\nFULL.\n";
                break;
            }
           
        Quant += TimeMax;

            std::cout << "\n STEP " << i ;
            std::cout << "\nNumber:     " << ChoosedMax << "\nPriority:  " << PriorityMax << "\nTime:       " << TimeMax
                << "\nTime gone: " << Quant << "\n Middle priority " << mpr<< "\n";
            s[ChoosedMax - 1] = 1;

            i++;
        }
    std::cout << "\nS: ";
    for (int j = 0; j < CountTask; j++) std::cout << s[j] << " ";
    std::cout << "\n\n";

    return;
}
int main()
{  
    MenuLoop:
    std::cout << "\nTask scheduler started, select the data entry type:\n1.data from keyboard\n2.data from file\n3.Randomize\n";
    std::cin >> entrytype;
 
    switch (entrytype)
    {
    case 1:
        std::cout << "selected 1\n";
        break;
    case 2:
        std::cout << "selected 2\n";
        break;
    case 3:
        std::cout << "selected 3\n";
        RandomEnter();
        break;
    default:
        std::cout << "selected something\n";
        break;
    } 
    goto MenuLoop;
}

