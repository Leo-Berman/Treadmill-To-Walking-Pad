import { vitePreprocess } from "@sveltejs/vite-plugin-svelte";
// import adapter from "@sveltejs/adapter-auto";
import adapter from '@sveltejs/adapter-static';

/** @type {import('@sveltejs/kit').Config} */
const config = {
	kit: {
		adapter: adapter({
			// default options are shown. On some platforms
			// these options are set automatically — see below
			pages: 'build',
			assets: 'build',
			// fallback: undefined,
			// precompress: false,
			strict: true
		})
	},
	// paths: {
	// 	base: "http://127.0.0.1:5000/",
	// 	assets: '',
	// },

  preprocess: [vitePreprocess({})],
};

export default config;
