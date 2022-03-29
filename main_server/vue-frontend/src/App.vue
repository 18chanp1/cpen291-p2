<template>
  <nav>
    | <router-link to="/">Home</router-link> |
    <router-link to="/about">About</router-link> |
    <router-link to="/musicinput">Upload music</router-link> | 
    <router-link to="/statsPage">Statistics</router-link> |
  </nav>
  <router-view/>
</template>

<style>

@font-face{
  font-family: "Noto Sans";
  src: local("Noto Sans"), url(./fonts/Noto_Sans/NotoSans-Regular.ttf) format("truetype");
}

@font-face{
  font-family: "Lato-Semibold";
  src: local("Lato-Semibold"), url(./fonts/Lato2OFL/Lato-Semibold.ttf) format("truetype");
}

#app {
  font-family: Lato, Helvetica, Arial, sans-serif;
  font-variant-ligatures: no-common-ligatures;
  text-rendering: optimizeLegibility;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  /* text-align: right; */
  color: #2c3e50;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #2c3e50;
  text-decoration: none;
}

nav a.router-link-exact-active {
  color: #42b983;
}
</style>
