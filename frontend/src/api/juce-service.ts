import * as Juce from "juce-framework-frontend";
import { ExampleResponse } from "../models/juce.models";

export default class JuceServices {
  static async getExampleResource(): Promise<ExampleResponse> {
    return fetch(Juce.getBackendResourceAddress("exampleResource")).then(
      (res) => res.json() as Promise<ExampleResponse>,
    );
  }

  static addEventListener(
    eventName: string,
    callback: (event: any) => void,
  ): void {
    (window as any).__JUCE__.backend.addEventListener(eventName, callback);
  }

  static removeEventListener(
    eventName: string,
    callback: (event: any) => void,
  ): void {
    (window as any).__JUCE__.backend.removeEventListener(eventName, callback);
  }
}
