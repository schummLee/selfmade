#include <stdio.h>
#include "received_data.h"

received_data::test_2_1000 (void test)
{
    printf ( "successful");
    if ( test() ) { printf(" entering phrase two")}
}

received_data::test() 
{
    printf ( " initalize test ....");
    received_data test_2_1000()
}

received_data::data_convert(data::received_data_form data)
{
    // convert operation here
    return data;
}

received_data::send_data_to_phrase_two(data::received_data_form data)
{
    return data;
}