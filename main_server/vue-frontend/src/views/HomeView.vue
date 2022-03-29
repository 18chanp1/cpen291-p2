<template>
  <h1>Welcome to the Music Educational Device</h1>

  <div class = "main">
    <div>
      <h2>Current Operating Mode</h2>
      PLACEHOLDER:

    </div>
    <div>
      <h2>Select your music choice here</h2>
      <drop_down></drop_down>
    </div>
    <div>Testificate</div>
  </div>

  <div class = "container">
    <hdr_bar title = "myTitle" />
    <hdr_bar title = "test" />
    <text_entry></text_entry>
    <drop_down></drop_down>
  </div>
</template>

<script>
  import drop_down from '/src/components/drop_down.vue'
  import hdr_bar from '/src/components/hdr_bar.vue'
  import text_entry from '/src/components/text_entry.vue'

  export default {
    name:'App',
    components: {
      hdr_bar,
      text_entry,
      drop_down
    }
  }
</script>

<style>
  h2 {
    font-family: Lato, Helvetica, Arial, sans-serif;
    -webkit-font-smoothing: antialiased;
    -moz-osx-font-smoothing: grayscale;
    text-align: left;
    color: #2c3e50;
    /* margin-top: 60px; */
  }

  .main {
    display: flex ;
    /* background-color: #9ADCFF; */
    border-radius: 10px;
    margin:10px;
    padding: 30px;
    justify-content: center;
  }

  .main > div {
  /* background-color: #f1f1f1; */
  margin: 20px;
  padding: 20px;
  font-size: 20px;
  text-align: left;
  border-radius: 10px;
  }

  .body {
    font-family: Noto Sans;
    font-size: 20px
  }

</style>