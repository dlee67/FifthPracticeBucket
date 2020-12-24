import { createReducer, on } from '@ngrx/store';
import { saveName } from './name.actions'

export const initialName = 'Nemo';

const _nameReducer = createReducer(
    initialName,
    on(saveName, (state) => state = 'different name'),
);

export function nameReducer(state, action) {
    return _nameReducer(state, action);
}