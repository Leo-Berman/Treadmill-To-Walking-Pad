<script>
import { Alert, Button, Range, Label, Card} from 'flowbite-svelte';
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
<div class="m-3 flex flex-row justify-center items-center text-center">
  <div class="me-10 flex flex-col">
    <Button class="mb-3" on:click={up}>Up</Button>
    <Button class="mb-3" on:click={down}>Down</Button>
    <Button on:click={inclineStop}>Stop</Button>
  </div>
  <Card class="items-center">
    <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">Treadmill Controlls</h5>
    <div>
      <p class="font-normal text-gray-700 dark:text-gray-400 leading-tight">Up: Increases the treadmill incline.</p>
      <p class="font-normal text-gray-700 dark:text-gray-400 leading-tight">Down: Decreases the treadmill incline.</p>
      <p class="font-normal text-gray-700 dark:text-gray-400 leading-tight">Stop: Stops the incline motor.</p>
      <p class="font-normal text-gray-700 dark:text-gray-400 leading-tight">Speed: Controlls how fast the treadmill is.</p>
    </div>
  </Card>  
</div>
<div class="m-3 flex flex-row justify-center items-center text-center" style="">
  <!-- <Alert>
    <span class="font-medium">Info alert!</span>
    Change a few things up and try submitting again.
  </Alert> -->
  <div class="m-10 w-96">
    <Label class="mt-3">Speed: {minmaxValue}</Label>
    <Range size="md" on:change={setSpeed} id="range-minmax" min="0" max="100" bind:value={minmaxValue}/>
  </div>
</div>