<script>
import { Alert, Button, Range, Label, Card, Toast} from 'flowbite-svelte';
import { FireOutline } from 'flowbite-svelte-icons';
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
<div class="mb-100">
  <div class="m-3 flex flex-row justify-center items-center text-center">
    <!-- <Toast>
      <FireOutline slot="icon" class="w-5 h-5 text-primary-500 bg-primary-100 dark:bg-primary-800 dark:text-primary-200" />
      Set yourself free.
    </Toast> -->
    <Card class="items-center">
      <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">Treadmill Controlls</h5>
      <div>
        <p class="justify-start text-justify font-normal text-gray-700 dark:text-gray-400 leading-tight word-wrap: break-word;">Up: Increases the treadmill incline.</p>
        <p class="justify-start text-justify font-normal text-gray-700 dark:text-gray-400 leading-tight word-wrap: break-word;">Down: Decreases the treadmill incline.</p>
        <p class="justify-start text-justify font-normal text-gray-700 dark:text-gray-400 leading-tight word-wrap: break-word;">Stop: Stop the incline motor.</p>
        <p class="justify-start text-justify font-normal text-gray-700 dark:text-gray-400 leading-tight word-wrap: break-word;">Speed: Speed of the treadmill belt.</p>
      </div>
    </Card>
  </div>
  <div class="m-3 flex flex-row justify-center items-center text-center" style="">
    <!-- <Alert>
      <span class="font-medium">Info alert!</span>
      Change a few things up and try submitting again.
    </Alert> -->
    <div class="me-5 flex flex-col">
      <Button class="mb-3" on:click={up}>Up</Button>
      <Button class="mb-3" on:click={down}>Down</Button>
      <Button on:click={inclineStop}>Stop</Button>
    </div>
    <div class="m-5 w-96">
      <Label class="mt-3">Speed: {minmaxValue}</Label>
      <Range class="rotate-0" size="md" on:change={setSpeed} id="range-minmax" min="0" max="100" bind:value={minmaxValue}/>
    </div>
  </div>
</div>