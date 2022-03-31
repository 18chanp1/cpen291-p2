<template>
  <div class="General">
    <h1>About the creators</h1>

    <table class = 'General' style = "width: 100%;">
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/JC.jpg">
        </td>
        <td style = "width: 50%;">
          <h2>James Chuang</h2>
            Backend database management and API handler
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/VQ.jpg">
        </td>
        <td style = "width: 50%;">
          <h2>Vanessa Quon</h2>
            Backend hardware interface developer.
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/ZX.jpg">
        </td>
        <td style = "width: 50%;">
          <h2>Zheng Xu</h2>
            Hardware constructor and acquisition manager. 
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/PC.png">
        </td>
        <td style = "width: 50%;">
          <h2>Paco Chan</h2>
            Frontend designer. 
        </td>
      </tr>
      
    </table>

  </div>
</template>

<style>
  h1{
    font-family: Lato-Semibold;
    font-size: 38px;
    text-align: left;
    border-bottom: 1px solid #af3c43;
    border-bottom-color: rgb(175, 60, 67);
    border-bottom-style: solid;
    border-bottom-width: 1px;
    margin-bottom: .2em;
    margin-top: 1em;
    padding-bottom: .2em;
  }
  h2{
    font-family: Lato-SemiBold;
    font-size: 34px;
    text-align: left;
    margin-bottom: 11.5px;
    margin-top: 38px;
  }
  p {
    font-family: Noto Sans;
    font-size: 20px;
    font-weight: 500;
    text-align: left;
    max-width: 65ch;
  }

  .General{
    margin: auto;
    max-width: 55ch;
    text-align: left;
    justify-content: left;
    font-family: Noto Sans;
    font-size: 20px;
    font-weight: 500;
    text-align: left;
  }

  img {
    max-width: 50%;

  }

  img {
    padding: 30px;
  }

</style>
