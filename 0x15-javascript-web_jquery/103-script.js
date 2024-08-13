/*
Task 13: Write a JavaScript script that fetches and prints how to say “Hello” depending on the language
You should use this API service: https://www.fourtonfish.com/hellosalut/hello/
...
*/

$(document).ready(function () {
    $('#btn_translate').click(function () {
        const langCode = $('#language_code').val();
        $.get(`https://www.fourtonfish.com/hellosalut/?lang=${langCode}`, function (data) {
        $('#hello').text(data.hello);
        });
    });
    
    $('#language_code').keypress(function (e) {
        if (e.which === 13) {
        $('#btn_translate').click();
        }
    });
    }
);
