<script>
import "../app.pcss";
import { DarkMode } from 'flowbite-svelte';
// let btnClass = 'text-gray-500 dark:text-gray-400 hover:bg-gray-100 dark:hover:bg-gray-700 rounded-lg text-xl p-2';
let btnClass = 'text-primary-500 dark:text-primary-600 border dark:border-gray-800 rounded-lg text-xl p-2';
</script>
<!-- <DarkMode></DarkMode> -->
<DarkMode {btnClass}/>
<!-- <DarkMode class="text-primary-500 dark:text-primary-600 border dark:border-gray-800"></DarkMode> -->
<slot></slot>