import * as Juce from "juce-framework-frontend";
import { ExampleResponse } from "../models/juce.models";

export default class JuceServices {
  static async getExampleResource(): Promise<ExampleResponse> {
    return fetch(Juce.getBackendResourceAddress("exampleResource")).then(
      (res) => res.json() as Promise<ExampleResponse>,
    );
  }
}
