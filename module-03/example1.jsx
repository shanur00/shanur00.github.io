import { useState } from "react";

export default function Picture() {
  const [click, setClick] = useState(false);

  function handleClick() {
    /* We are checking if the click is false or not.  
       If flase then we just set the clik true that removes the backdround.
    */
    if (!click) {
      setClick(!click);
    }
  }

  function handleBackground() {
    if (click) {
      /* If the click is true then definately there is no background. 
         So setting click to false will get back the background.    
      */
      setClick(!click);
    }
  }

  return (
    <div
      className={click ? "background" : "background background--active"}
      onClick={handleBackground}
    >
      <img
        className={click ? "picture picture--active" : "picture"}
        alt="Rainbow houses in Kampung Pelangi, Indonesia"
        src="https://i.imgur.com/5qwVYb1.jpeg"
        onClick={(e) => {
          /* Stopping propagation. We can see that img's parent has also a click 
             event. So we do not want to pass the event up to the parent (div).
          */
          e.stopPropagation();
          handleClick();
        }}
      />
    </div>
  );
}
