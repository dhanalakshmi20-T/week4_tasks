Iterating Through Containers and Finding Elements
Goal: Practice iterating through containers and retrieving specific elements.
Scenario:
You are tasked with highlighting all active widgets on the HMI screen. The HMI has two main containers:
std::vector for dynamic widgets.
std::set for static widgets.
Steps:
Populate Containers:
Initialize a std::vector<std::string> with dynamic widgets ("Speedometer", "Tachometer", etc.).
Initialize a std::set<std::string> with static widgets ("Logo", "WarningLights").
Use Iterators:
Print all dynamic widgets using an iterator.
Check if a specific widget (e.g., "WarningLights") is in the std::set using std::set::find.
Advanced Iteration:
Combine both containers into a std::vector<std::string> using std::copy.
Use std::find to locate a specific widget in the combined container.
Output Results:
Print the widget list dynamically and show results of widget searches.
Program:
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm> 
using namespace std;
int main() 
{
    vector<string> dynamicWidgets = {"Speedometer", "Tachometer", "FuelGauge"};
    set<string> staticWidgets = {"Logo", "WarningLights", "Temperature"};
    cout << "Dynamic Widgets:\n";
    for (vector<string>::iterator it = dynamicWidgets.begin(); it != dynamicWidgets.end(); ++it) 
    {
        cout << *it << endl;
    }

    auto findResult = staticWidgets.find("WarningLights");
    if (findResult != staticWidgets.end()) 
    {
        cout << "WarningLights is in the static widgets container.";
    } 
    else 
    {
        cout << "WarningLights not found in static widgets container.";
    }

    vector<string> allWidgets;
    copy(dynamicWidgets.begin(), dynamicWidgets.end(), back_inserter(allWidgets));
    copy(staticWidgets.begin(), staticWidgets.end(), back_inserter(allWidgets));
    cout << "\nAll Widgets (combined):\n";
    for (const auto& widget : allWidgets) 
    {
        cout << widget << endl;
    }

    string searchWidget = "Speedometer";
    auto foundWidget = find(allWidgets.begin(), allWidgets.end(), searchWidget);
    if (foundWidget != allWidgets.end()) 
    {
        cout << searchWidget << " found in the combined widget list.\n";
    } 
    else 
    {
        cout << searchWidget << " not found in the combined widget list.\n";
    }
    return 0;
}
Output:
Dynamic Widgets:
Speedometer
Tachometer
FuelGauge
WarningLights is in the static widgets container.
All Widgets (combined):
Speedometer
Tachometer
FuelGauge
Logo
Temperature
WarningLights
Speedometer found in the combined widget list.