<form action="index.php">
<h2> Let's play a guessing game!<br> Keep guessing until you get the right number. </h2>
<?php
   extract($_REQUEST);
   if ($button=="clear game")
   {
      clearGame($game,$randomnum);
   }
   elseif ($button=="submit guess")
   {
      updateGame($game,$newguess,$randomnum);
   }
 gamePage($game);
 passData($game,$randomnum,$newguess);

function clearGame(&$game, &$randomnum)
{
   $game=NULL;
   $randomnum = rand(1,1000);
   $game = $game."Random Number: $randomnum\n";
}

function updateGame(&$game,$newguess,$randomnum)
{
   if ($newguess < $randomnum){
     $game = $game . "$newguess -- Too Small :(\n";
   }
   elseif ($newguess > $randomnum) {
     $game = $game . "$newguess -- Too Big :(\n";
   }
   elseif ($newguess == $randomnum) {
     $game = $game . "$newguess -- That is the correct number! :)\n";
   }
   else
   {
     $game = $game . "$newguess -- insert a number \n";
   }
}

function gamePage($game)
{
   echo <<< HERE
      <textarea rows="15" cols="40">$game</textarea>
      <h3>new guess<input type="text" name="newguess" autocomplete="off"></h3>
      <input type="submit" name="button" value="submit guess">
      <input type="submit" name="button" value="clear game">
HERE;
}

function passData($game,$randomnum,$newguess)
{
   echo <<< HERE
      <input type="hidden" name="game" value="$game">
      <input type="hidden" name="randomnum" value="$randomnum">

HERE;
}

?>
</form>
<style>
html{
  background-color: rgb(214, 226, 233);
}
</style>
