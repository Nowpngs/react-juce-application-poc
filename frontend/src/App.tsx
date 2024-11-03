import { useEffect, useState } from "react";
import logo from "./logo.svg";
import "./App.css";

import JuceServices from "./api/juce-service";
import Plot from "react-plotly.js";
function App() {
  const [rmsLevels, setRmsLevels] = useState<Array<number | null>>([]);

  useEffect(() => {
    getExampleResource();

    JuceServices.addEventListener(
      "audioLevels",
      (event: Array<number | null>) => {
        setRmsLevels(event);
      },
    );

    return () => {
      JuceServices.removeEventListener("audioLevels", () => {
        console.log("Event listener removed");
      });
    };
  }, []);

  async function getExampleResource(): Promise<void> {
    await JuceServices.getExampleResource()
      .then((data) => {
        console.log(data.exampleProperty);
      })
      .catch((error) => {
        console.error(error);
      });
  }

  const processedRmsLevels = rmsLevels.map((level) =>
    level !== null ? level + 100 : 0,
  );

  const data = [
    {
      x: [`Level 1`, `Level 2`, `Level 3`, `Level 4`],
      y: processedRmsLevels,
      base: [-100, -100, -100, -100],
      type: "bar",
      marker: { color: "green" },
      name: "RMS Levels",
    },
  ];

  const layout = {
    title: "RMS Level Meter",
    yaxis: {
      title: "Level (dB)",
      range: [-100, 0], // Set the y-axis range from -100 to 0
      autorange: false,
      ticks: "outside",
      tickvals: [-100, -80, -60, -40, -20, 0],
      ticktext: ["-100", "-80", "-60", "-40", "-20", "0"],
    },
    showlegend: false,
  };

  const config = {
    responsive: true, // Makes the chart responsive
    staticPlot: false, // Makes the chart static
  };

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.tsx</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
      </header>

      <div style={{ marginTop: "20px" }}>
        <Plot
          data={data}
          layout={layout}
          style={{ width: "100%", height: "400px" }}
          config={config}
        />
      </div>
    </div>
  );
}

export default App;
