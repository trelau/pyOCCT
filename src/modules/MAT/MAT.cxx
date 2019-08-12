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

void bind_MAT_Side(py::module &);
void bind_MAT_Arc(py::module &);
void bind_MAT_SequenceOfArc(py::module &);
void bind_MAT_BasicElt(py::module &);
void bind_MAT_SequenceOfBasicElt(py::module &);
void bind_MAT_Node(py::module &);
void bind_MAT_DataMapOfIntegerBasicElt(py::module &);
void bind_MAT_DataMapIteratorOfDataMapOfIntegerBasicElt(py::module &);
void bind_MAT_Bisector(py::module &);
void bind_MAT_DataMapOfIntegerBisector(py::module &);
void bind_MAT_DataMapIteratorOfDataMapOfIntegerBisector(py::module &);
void bind_MAT_DataMapOfIntegerArc(py::module &);
void bind_MAT_DataMapIteratorOfDataMapOfIntegerArc(py::module &);
void bind_MAT_DataMapOfIntegerNode(py::module &);
void bind_MAT_DataMapIteratorOfDataMapOfIntegerNode(py::module &);
void bind_MAT_Edge(py::module &);
void bind_MAT_Graph(py::module &);
void bind_MAT_ListOfBisector(py::module &);
void bind_MAT_ListOfEdge(py::module &);
void bind_MAT_TListNodeOfListOfBisector(py::module &);
void bind_MAT_TListNodeOfListOfEdge(py::module &);
void bind_MAT_Zone(py::module &);

PYBIND11_MODULE(MAT, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");

bind_MAT_Side(mod);
bind_MAT_Arc(mod);
bind_MAT_SequenceOfArc(mod);
bind_MAT_BasicElt(mod);
bind_MAT_SequenceOfBasicElt(mod);
bind_MAT_Node(mod);
bind_MAT_DataMapOfIntegerBasicElt(mod);
bind_MAT_DataMapIteratorOfDataMapOfIntegerBasicElt(mod);
bind_MAT_Bisector(mod);
bind_MAT_DataMapOfIntegerBisector(mod);
bind_MAT_DataMapIteratorOfDataMapOfIntegerBisector(mod);
bind_MAT_DataMapOfIntegerArc(mod);
bind_MAT_DataMapIteratorOfDataMapOfIntegerArc(mod);
bind_MAT_DataMapOfIntegerNode(mod);
bind_MAT_DataMapIteratorOfDataMapOfIntegerNode(mod);
bind_MAT_Edge(mod);
bind_MAT_Graph(mod);
bind_MAT_ListOfBisector(mod);
bind_MAT_ListOfEdge(mod);
bind_MAT_TListNodeOfListOfBisector(mod);
bind_MAT_TListNodeOfListOfEdge(mod);
bind_MAT_Zone(mod);

}
