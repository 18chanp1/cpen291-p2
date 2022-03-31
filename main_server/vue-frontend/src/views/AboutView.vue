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
            Backend database management and API handler. 
            <br/>
            Born to owners of Taiwan Semiconductor
            Manufacturing Company (TSMC), he roamed free around the research and manufacturing fabs.
            He was always interested in leading edge computing hardware and began assisting the design
            of chips at TSMC at a very young age. 
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/VQ.jpg">
        </td>
        <td style = "width: 50%;">
          <h2>Vanessa Quon</h2>
            Backend hardware interface developer.
            <br/>
            Founder of several startups in Silicon Valley, acting as an anonymous contributor to many
            major programs, desktop and mobile. However, no one has ever confirmed the existence of 
            this person, and has no idea who this person is. 
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/ZX.jpg">
        </td>
        <td style = "width: 50%;">
          <h2>Zheng Xu</h2>
            Hardware constructor and acquisition manager. 

            Child of a mad scientist, Zheng was always an inquirer of the world around him.
            He seeks to understand the world around him. In fact, he holds the current class
            record for most questions asked in lecture. He often asks provoking and thoughtful
            questions that enable others to deepen their understanding. His primary contributions
            to this projects include asking probing questions about the quality of other team members'
            code. In fact, he asks more questions than lines of code he has written. 
        </td>
      </tr>
      <tr>
        <td style = "width: 50%;">
          <img src= "../imgs/PC.png">
        </td>
        <td style = "width: 50%;">
          <h2>Paco Chan</h2>
            Frontend designer. 

            Enjoys looking at attractive things and people. Originally considering a degree in design,
            the harsh reality of high unemployment in Canada forced him to reconsider his choices. 
            Although he is disatisfied with his choices in life, and does not enjoy staring at code all day,
            he regrets nothing and would pick this path again. 
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
