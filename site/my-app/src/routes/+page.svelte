<script>
import { Alert, Button, Range, Label} from 'flowbite-svelte';
//   import { ThumbsUpSolid, ThumbsDownSolid } from 'flowbite-svelte-icons';
let minmaxValue = 0;

const scream = () => {
  console.log("Ahhh");
},

inclineStop = async function() {
    console.log("Stop Incline");
    const response = await fetch("/inclineStop");
    const text = await response.text();
    console.log(text);
},
up = async function() {
    console.log("Up");
    const response = await fetch("/up");
    const text = await response.text();
    console.log(text);
},
down = async function() {
    console.log("Down");
    const response = await fetch("/down");
    const text = await response.text();
    console.log(text);
},
setSpeed = async function() {
    console.log(`Set the speed to ${minmaxValue}`);
    const response = await fetch(`/speed/${minmaxValue}`);
    const text = await response.text();
    console.log(text);
}
</script>

<div class="p-8">
  <!-- <Alert>
    <span class="font-medium">Info alert!</span>
    Change a few things up and try submitting again.
  </Alert> -->
  <div class="pb-2">
    <Button on:click={up}>Up</Button>
    <Button on:click={down}>Down</Button>
  </div>
  <Label>Speed: {minmaxValue}</Label>
  <Range on:change={setSpeed} id="range-minmax" min="0" max="100" bind:value={minmaxValue} style=""/>
</div>