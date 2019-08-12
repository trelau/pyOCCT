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

void bind_TFunction_ExecutionStatus(py::module &);
void bind_TFunction_Function(py::module &);
void bind_TFunction_Driver(py::module &);
void bind_TFunction_DataMapOfGUIDDriver(py::module &);
void bind_TFunction_DataMapIteratorOfDataMapOfGUIDDriver(py::module &);
void bind_TFunction_Array1OfDataMapOfGUIDDriver(py::module &);
void bind_TFunction_DataMapOfLabelListOfLabel(py::module &);
void bind_TFunction_DataMapIteratorOfDataMapOfLabelListOfLabel(py::module &);
void bind_TFunction_DoubleMapOfIntegerLabel(py::module &);
void bind_TFunction_DoubleMapIteratorOfDoubleMapOfIntegerLabel(py::module &);
void bind_TFunction_HArray1OfDataMapOfGUIDDriver(py::module &);
void bind_TFunction_DriverTable(py::module &);
void bind_TFunction_GraphNode(py::module &);
void bind_TFunction_IFunction(py::module &);
void bind_TFunction_Iterator(py::module &);
void bind_TFunction_Logbook(py::module &);
void bind_TFunction_Scope(py::module &);

PYBIND11_MODULE(TFunction, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

bind_TFunction_ExecutionStatus(mod);
bind_TFunction_Function(mod);
bind_TFunction_Driver(mod);
bind_TFunction_DataMapOfGUIDDriver(mod);
bind_TFunction_DataMapIteratorOfDataMapOfGUIDDriver(mod);
bind_TFunction_Array1OfDataMapOfGUIDDriver(mod);
bind_TFunction_DataMapOfLabelListOfLabel(mod);
bind_TFunction_DataMapIteratorOfDataMapOfLabelListOfLabel(mod);
bind_TFunction_DoubleMapOfIntegerLabel(mod);
bind_TFunction_DoubleMapIteratorOfDoubleMapOfIntegerLabel(mod);
bind_TFunction_HArray1OfDataMapOfGUIDDriver(mod);
bind_TFunction_DriverTable(mod);
bind_TFunction_GraphNode(mod);
bind_TFunction_IFunction(mod);
bind_TFunction_Iterator(mod);
bind_TFunction_Logbook(mod);
bind_TFunction_Scope(mod);

}
