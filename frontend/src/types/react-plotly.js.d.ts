declare module 'react-plotly.js' {
    import * as React from 'react';
  
    export interface PlotProps {
      data: any; // You can define more specific types based on your data structure
      layout?: any; // You can also define more specific types for layout
      config?: any; // Define config types if necessary
      style?: React.CSSProperties;
      className?: string;
    }
  
    export default class Plot extends React.Component<PlotProps> {}
  }
  