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

void bind_MoniTool_ValueType(py::module &);
void bind_MoniTool_SignText(py::module &);
void bind_MoniTool_ValueInterpret(py::module &);
void bind_MoniTool_ValueSatisfies(py::module &);
void bind_MoniTool_TypedValue(py::module &);
void bind_MoniTool_AttrList(py::module &);
void bind_MoniTool_CaseData(py::module &);
void bind_MoniTool_DataInfo(py::module &);
void bind_MoniTool_DataMapOfShapeTransient(py::module &);
void bind_MoniTool_DataMapIteratorOfDataMapOfShapeTransient(py::module &);
void bind_MoniTool_MTHasher(py::module &);
void bind_MoniTool_DataMapOfTimer(py::module &);
void bind_MoniTool_DataMapIteratorOfDataMapOfTimer(py::module &);
void bind_MoniTool_Element(py::module &);
void bind_MoniTool_ElemHasher(py::module &);
void bind_MoniTool_SequenceOfElement(py::module &);
void bind_MoniTool_HSequenceOfElement(py::module &);
void bind_MoniTool_IndexedDataMapOfShapeTransient(py::module &);
void bind_MoniTool_IntVal(py::module &);
void bind_MoniTool_RealVal(py::module &);
void bind_MoniTool_SignShape(py::module &);
void bind_MoniTool_Stat(py::module &);
void bind_MoniTool_Timer(py::module &);
void bind_MoniTool_TimerSentry(py::module &);
void bind_MoniTool_TransientElem(py::module &);

PYBIND11_MODULE(MoniTool, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.OSD");

bind_MoniTool_ValueType(mod);
bind_MoniTool_SignText(mod);
bind_MoniTool_ValueInterpret(mod);
bind_MoniTool_ValueSatisfies(mod);
bind_MoniTool_TypedValue(mod);
bind_MoniTool_AttrList(mod);
bind_MoniTool_CaseData(mod);
bind_MoniTool_DataInfo(mod);
bind_MoniTool_DataMapOfShapeTransient(mod);
bind_MoniTool_DataMapIteratorOfDataMapOfShapeTransient(mod);
bind_MoniTool_MTHasher(mod);
bind_MoniTool_DataMapOfTimer(mod);
bind_MoniTool_DataMapIteratorOfDataMapOfTimer(mod);
bind_MoniTool_Element(mod);
bind_MoniTool_ElemHasher(mod);
bind_MoniTool_SequenceOfElement(mod);
bind_MoniTool_HSequenceOfElement(mod);
bind_MoniTool_IndexedDataMapOfShapeTransient(mod);
bind_MoniTool_IntVal(mod);
bind_MoniTool_RealVal(mod);
bind_MoniTool_SignShape(mod);
bind_MoniTool_Stat(mod);
bind_MoniTool_Timer(mod);
bind_MoniTool_TimerSentry(mod);
bind_MoniTool_TransientElem(mod);

}
