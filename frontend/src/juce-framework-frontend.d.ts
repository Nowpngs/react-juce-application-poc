declare module "juce-framework-frontend" {
  
  /**
   * Returns a function that calls a native function registered on the JUCE backend.
   * The returned function forwards all provided arguments to the native function and returns a Promise.
   *
   * @param name - The name of the native function to invoke.
   * @returns A function that, when called, returns a Promise resolving with the native function's result.
   */
  export function getNativeFunction(name: string): (...args: any[]) => Promise<any>;

  /**
   * Represents a slider's state synchronized with the JUCE backend.
   */
  export class SliderState {
    /**
     * Creates a new SliderState instance connected to a backend WebSliderRelay.
     *
     * @param name - The unique name identifying the corresponding WebSliderRelay on the backend.
     */
    constructor(name: string);

    /**
     * Sets the normalized value [0, 1] of the backend parameter.
     *
     * @param newValue - The new normalized value to set.
     */
    setNormalisedValue(newValue: number): void;

    /**
     * Should be called when the user starts interacting with the slider.
     */
    sliderDragStarted(): void;

    /**
     * Should be called when the user finishes interacting with the slider.
     */
    sliderDragEnded(): void;

    /**
     * Returns the scaled value of the parameter, corresponding to the backend's representation.
     *
     * @returns The scaled value.
     */
    getScaledValue(): number;

    /**
     * Returns the normalized value [0, 1] of the backend parameter.
     *
     * @returns The normalized value.
     */
    getNormalisedValue(): number;

    /**
     * Event triggered when the slider's value changes.
     * You can add listeners to respond to value changes.
     */
    valueChangedEvent: ListenerList<(scaledValue: number) => void>;

    /**
     * Event triggered when the slider's properties change.
     * You can add listeners to respond to property changes.
     */
    propertiesChangedEvent: ListenerList<(properties: SliderProperties) => void>;

    /**
     * The current properties of the slider.
     */
    properties: SliderProperties;
  }

  /**
   * Represents a toggle's state synchronized with the JUCE backend.
   */
  export class ToggleState {
    /**
     * Creates a new ToggleState instance connected to a backend WebToggleRelay.
     *
     * @param name - The unique name identifying the corresponding WebToggleRelay on the backend.
     */
    constructor(name: string);

    /**
     * Gets the current value of the toggle.
     *
     * @returns The current boolean value.
     */
    getValue(): boolean;

    /**
     * Sets the value of the toggle and informs the backend.
     *
     * @param newValue - The new boolean value to set.
     */
    setValue(newValue: boolean): void;

    /**
     * Event triggered when the toggle's value changes.
     * You can add listeners to respond to value changes.
     */
    valueChangedEvent: ListenerList<(value: boolean) => void>;

    /**
     * Event triggered when the toggle's properties change.
     * You can add listeners to respond to property changes.
     */
    propertiesChangedEvent: ListenerList<(properties: ToggleProperties) => void>;

    /**
     * The current properties of the toggle.
     */
    properties: ToggleProperties;
  }

  /**
   * Represents a combo box's state synchronized with the JUCE backend.
   */
  export class ComboBoxState {
    /**
     * Creates a new ComboBoxState instance connected to a backend WebComboBoxRelay.
     *
     * @param name - The unique name identifying the corresponding WebComboBoxRelay on the backend.
     */
    constructor(name: string);

    /**
     * Gets the index of the currently selected choice.
     *
     * @returns The index of the selected choice.
     */
    getChoiceIndex(): number;

    /**
     * Sets the selected choice by index and informs the backend.
     *
     * @param index - The index of the choice to select.
     */
    setChoiceIndex(index: number): void;

    /**
     * Event triggered when the combo box's value changes.
     * You can add listeners to respond to value changes.
     */
    valueChangedEvent: ListenerList<(value: number) => void>;

    /**
     * Event triggered when the combo box's properties change.
     * You can add listeners to respond to property changes.
     */
    propertiesChangedEvent: ListenerList<(properties: ComboBoxProperties) => void>;

    /**
     * The current properties of the combo box.
     */
    properties: ComboBoxProperties;
  }

  /**
   * Appends a platform-specific prefix to the given path to ensure that requests are routed to the backend's ResourceProvider.
   *
   * @param path - The resource path to modify.
   * @returns The platform-specific resource address.
   */
  export function getBackendResourceAddress(path: string): string;

  /**
   * Helps manage the control parameter index based on mouse movement within the DOM.
   */
  export class ControlParameterIndexUpdater {
    /**
     * Creates a new ControlParameterIndexUpdater instance.
     *
     * @param controlParameterIndexAnnotation - The attribute name used to identify control parameters in the DOM.
     */
    constructor(controlParameterIndexAnnotation: string);

    /**
     * Should be called during each mousemove event to update the control parameter index based on the current DOM element under the cursor.
     *
     * @param event - The mousemove event.
     */
    handleMouseMove(event: MouseEvent): void;
  }

  /**
   * Utility class to manage a list of listeners.
   */
  export class ListenerList<T = any> {
    /**
     * Creates a new ListenerList instance.
     */
    constructor();

    /**
     * Adds a new listener to the list.
     *
     * @param fn - The listener function to add.
     * @returns The unique ID of the added listener.
     */
    addListener(fn: T): number;

    /**
     * Removes a listener from the list by its unique ID.
     *
     * @param id - The unique ID of the listener to remove.
     */
    removeListener(id: number): void;

    /**
     * Calls all listeners in the list with the provided payload.
     *
     * @param payload - The data to pass to each listener.
     */
    callListeners(payload: any): void;
  }

  /**
   * Properties associated with a SliderState.
   */
  export interface SliderProperties {
    start: number;
    end: number;
    skew: number;
    name: string;
    label: string;
    numSteps: number;
    interval: number;
    parameterIndex: number;
  }

  /**
   * Properties associated with a ToggleState.
   */
  export interface ToggleProperties {
    name: string;
    parameterIndex: number;
  }

  /**
   * Properties associated with a ComboBoxState.
   */
  export interface ComboBoxProperties {
    name: string;
    parameterIndex: number;
    choices: string[];
  }

  /**
   * Retrieves the current state of a slider identified by name.
   * If the SliderState does not exist, it will be created and synchronized with the backend.
   *
   * @param name - The unique name of the slider.
   * @returns The SliderState instance.
   */
  export function getSliderState(name: string): SliderState;

  /**
   * Retrieves the current state of a toggle identified by name.
   * If the ToggleState does not exist, it will be created and synchronized with the backend.
   *
   * @param name - The unique name of the toggle.
   * @returns The ToggleState instance.
   */
  export function getToggleState(name: string): ToggleState;

  /**
   * Retrieves the current state of a combo box identified by name.
   * If the ComboBoxState does not exist, it will be created and synchronized with the backend.
   *
   * @param name - The unique name of the combo box.
   * @returns The ComboBoxState instance.
   */
  export function getComboBoxState(name: string): ComboBoxState;
}
