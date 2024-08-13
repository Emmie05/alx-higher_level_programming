/*
Task 4: Write a JavaScript script that toggles the class of the <header> element when the user clicks on the tag DIV#toggle_header
*/

$(document).ready(function () {
    $('#toggle_header').click(function () {
        $('header').toggleClass('red green');
    });
    }
);
