/*
Task 6: Write a JavaScript script that updates the text of the <header> element to New Header!!! when the user clicks on DIV#update_header
*/

$('DIV#update_header').click(function () {
    $('header').text('New Header!!!');
    }
);
