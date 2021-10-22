echo 'Pick a quote-sayer from:'
echo 'C3PO'
echo 'Chewie'
echo 'Darth'
echo 'Emperor'
echo 'Governor'
echo 'Kenobi'
echo 'Leia'
echo 'Obi-Wan'
echo 'Princess'
echo 'Solo'
echo 'Vader'
echo '... or enter QUIT to exit the script.'
read userInput
until [ $userInput = "QUIT"]
do
    if [ $userInput = "C3PO" ]
    then 
        ls ./C3PO 
        cat quote.txt
    elif [ $userInput = "Chewie" ]
    then
        ls ./Chewie
        cat quote.txt
    elif [ $userInput = "Darth" ]
    then
        ls ./Darth
        cat quote.txt
    elif [ $userInput = "Emperor" ]
    then
        ls ./Emperor
        cat quote.txt
    elif [ $userInput = "Governor" ]
    then
        ls ./Governor
        cat quote.txt
    elif [ $userInput = "Kenobi" ]
    then
        ls ./Kenobi
        cat quote.txt
    elif [ $userInput = "Leia" ]
    then
        ls ./Leia
        cat quote.txt
    elif [ $userInput = "Obi-Wan" ]
    then
        ls ./Obi-Wan
        cat quote.txt
    elif [ $userInput = "Princess" ]
    then
        ls ./Princess
        cat quote.txt
    elif [ $userInput = "Solo" ]
    then
        ls ./Solo
        cat quote.txt
    elif [ $userInput = "Vader" ]
    then
        ls ./Vader
        cat quote.txt
    else
        exit 7
    fi
done

exit 0