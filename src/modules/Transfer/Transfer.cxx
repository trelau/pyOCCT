/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

void bind_Transfer_StatusResult(py::module &);
void bind_Transfer_StatusExec(py::module &);
void bind_Transfer_UndefMode(py::module &);
void bind_Transfer_Finder(py::module &);
void bind_Transfer_SequenceOfFinder(py::module &);
void bind_Transfer_HSequenceOfFinder(py::module &);
void bind_Transfer_Binder(py::module &);
void bind_Transfer_FindHasher(py::module &);
void bind_Transfer_TransferMapOfProcessForFinder(py::module &);
void bind_Transfer_ActorOfProcessForFinder(py::module &);
void bind_Transfer_ActorOfFinderProcess(py::module &);
void bind_Transfer_TransferMapOfProcessForTransient(py::module &);
void bind_Transfer_ProcessForTransient(py::module &);
void bind_Transfer_TransientProcess(py::module &);
void bind_Transfer_ActorOfProcessForTransient(py::module &);
void bind_Transfer_ActorOfTransientProcess(py::module &);
void bind_Transfer_ProcessForFinder(py::module &);
void bind_Transfer_FinderProcess(py::module &);
void bind_Transfer_TransferOutput(py::module &);
void bind_Transfer_TransferDispatch(py::module &);
void bind_Transfer_ActorDispatch(py::module &);
void bind_Transfer_SimpleBinderOfTransient(py::module &);
void bind_Transfer_BinderOfTransientInteger(py::module &);
void bind_Transfer_DataInfo(py::module &);
void bind_Transfer_DispatchControl(py::module &);
void bind_Transfer_SequenceOfBinder(py::module &);
void bind_Transfer_HSequenceOfBinder(py::module &);
void bind_Transfer_TransferIterator(py::module &);
void bind_Transfer_IteratorOfProcessForFinder(py::module &);
void bind_Transfer_IteratorOfProcessForTransient(py::module &);
void bind_Transfer_MapContainer(py::module &);
void bind_Transfer_MultipleBinder(py::module &);
void bind_Transfer_ResultFromModel(py::module &);
void bind_Transfer_ResultFromTransient(py::module &);
void bind_Transfer_TransferFailure(py::module &);
void bind_Transfer_TransferDeadLoop(py::module &);
void bind_Transfer_TransferInput(py::module &);
void bind_Transfer_TransientListBinder(py::module &);
void bind_Transfer_TransientMapper(py::module &);
void bind_Transfer_VoidBinder(py::module &);

PYBIND11_MODULE(Transfer, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Message");

bind_Transfer_StatusResult(mod);
bind_Transfer_StatusExec(mod);
bind_Transfer_UndefMode(mod);
bind_Transfer_Finder(mod);
bind_Transfer_SequenceOfFinder(mod);
bind_Transfer_HSequenceOfFinder(mod);
bind_Transfer_Binder(mod);
bind_Transfer_FindHasher(mod);
bind_Transfer_TransferMapOfProcessForFinder(mod);
bind_Transfer_ActorOfProcessForFinder(mod);
bind_Transfer_ActorOfFinderProcess(mod);
bind_Transfer_TransferMapOfProcessForTransient(mod);
bind_Transfer_ProcessForTransient(mod);
bind_Transfer_TransientProcess(mod);
bind_Transfer_ActorOfProcessForTransient(mod);
bind_Transfer_ActorOfTransientProcess(mod);
bind_Transfer_ProcessForFinder(mod);
bind_Transfer_FinderProcess(mod);
bind_Transfer_TransferOutput(mod);
bind_Transfer_TransferDispatch(mod);
bind_Transfer_ActorDispatch(mod);
bind_Transfer_SimpleBinderOfTransient(mod);
bind_Transfer_BinderOfTransientInteger(mod);
bind_Transfer_DataInfo(mod);
bind_Transfer_DispatchControl(mod);
bind_Transfer_SequenceOfBinder(mod);
bind_Transfer_HSequenceOfBinder(mod);
bind_Transfer_TransferIterator(mod);
bind_Transfer_IteratorOfProcessForFinder(mod);
bind_Transfer_IteratorOfProcessForTransient(mod);
bind_Transfer_MapContainer(mod);
bind_Transfer_MultipleBinder(mod);
bind_Transfer_ResultFromModel(mod);
bind_Transfer_ResultFromTransient(mod);
bind_Transfer_TransferFailure(mod);
bind_Transfer_TransferDeadLoop(mod);
bind_Transfer_TransferInput(mod);
bind_Transfer_TransientListBinder(mod);
bind_Transfer_TransientMapper(mod);
bind_Transfer_VoidBinder(mod);

}
