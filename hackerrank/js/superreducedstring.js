process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function super_reduced_string(s){

    if(s.length === 0){
        return "Empty String";
    }

    for(var i = 0; i < s.length; i++){
        if(s[i] === s[i+1]){
            if(i == 0){
                s = super_reduced_string(s.substring(i+2));
            } else if(i === s.length - 1 ){
                s = super_reduced_string(s.substring(0, i));
            } else {
                s = super_reduced_string(s.substring(0, i) + s.substring(i+2))
            }

        }
    }

    return s;
    // Complete this function
}

function main() {
    var s = readLine();
    var result = super_reduced_string(s);
    process.stdout.write("" + result + "\n");

}
