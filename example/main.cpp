#include <iostream>
#include "../headers/xml.h"

#define FILENAME "test.xml"

int main()
{
    XML xml;
    xml.read(FILENAME);

    xml["GROUP1"]["SUBGROUP1"] = "value1";
    xml["GROUP1"]["SUBGROUP2"] = 12;
    xml["GROUP1"]["SUBGROUP3"] = 0.0;
    xml["GROUP1"]["SUBGROUP4"] = 'T';
    xml["GROUP1"]["SUBGROUP5"] = "HASHED VALUE";
    xml["GROUP1"]["SUBGROUP5"].setHash(true);


    xml["GROUP2"]["SUBGROUP1"] = "value1";
    xml["GROUP2"]["SUBGROUP2"] = 12;
    xml["GROUP2"]["SUBGROUP3"] = 0.0;
    xml["GROUP2"]["SUBGROUP4"] = 'T';

    xml["GROUP3"]["SUBGROUP1"] = "value1";
    xml["GROUP3"]["SUBGROUP2"] = "value2";

    std::cout << xml["GROUP1"]["SUBGROUP5"] << std::endl;
    xml -= xml["GROUP1"]["SUBGROUP4"];
    xml["GROUP3"] += xml["GROUP1"]["SUBGROUP5"];
    xml["GROUP3"]["SUBGROUP5"].setHash(false);
    std::cout << xml["GROUP3"]["SUBGROUP5"] << std::endl;
    xml -= xml["GROUP2"];

    xml.write(FILENAME);
    return 0;
}