import { createSelector } from '@ngrx/store';

export interface AppState {
  count: number;
  name: string;
}
 
export const selectFeature = (state: AppState) => {
    return state; 
};
 
export const selectFeatureCount = createSelector(
  selectFeature,
  (state: AppState) => {
    return state.count; // From the looks of things, this is what's being assigned to count$.
  }
);