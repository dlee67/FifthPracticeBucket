import { createSelector } from '@ngrx/store';

export interface AppState {
  count: number;
}
 
export const selectFeature = (state: AppState) => {
    return state; 
};
 
export const selectFeatureCount = createSelector(
  selectFeature,
  (state: AppState) => {
    return state.count;
  }
);