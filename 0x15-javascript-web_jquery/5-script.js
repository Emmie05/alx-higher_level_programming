/*
Task 5: Write a JavaScript script that adds a <li> element to a list when the user clicks on the tag DIV#add_item:

The new element must be: <li>Item</li>
The new element must be added to UL.my_list
You can’t use document.querySelector to select the HTML tag
You must use the JQuery API
*/

$('DIV#add_item').click(function () {
    $('UL.my_list').append('<li>Item</li>');
    }
);
