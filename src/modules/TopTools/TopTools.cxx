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

void bind_TopTools_ListOfShape(py::module &);
void bind_TopTools_ListIteratorOfListOfShape(py::module &);
void bind_TopTools_DataMapOfIntegerListOfShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape(py::module &);
void bind_TopTools_ShapeMapHasher(py::module &);
void bind_TopTools_MapOfShape(py::module &);
void bind_TopTools_MapIteratorOfMapOfShape(py::module &);
void bind_TopTools_IndexedMapOfShape(py::module &);
void bind_TopTools_IndexedDataMapOfShapeListOfShape(py::module &);
void bind_TopTools_DataMapOfShapeListOfShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeListOfShape(py::module &);
void bind_TopTools_DataMapOfShapeShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeShape(py::module &);
void bind_TopTools_DataMapOfShapeBox(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeBox(py::module &);
void bind_TopTools_OrientedShapeMapHasher(py::module &);
void bind_TopTools_IndexedMapOfOrientedShape(py::module &);
void bind_TopTools_DataMapOfShapeInteger(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeInteger(py::module &);
void bind_TopTools_IndexedDataMapOfShapeReal(py::module &);
void bind_TopTools_ListOfListOfShape(py::module &);
void bind_TopTools_ListIteratorOfListOfListOfShape(py::module &);
void bind_TopTools_DataMapOfOrientedShapeInteger(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfOrientedShapeInteger(py::module &);
void bind_TopTools_IndexedDataMapOfShapeShape(py::module &);
void bind_TopTools_SequenceOfShape(py::module &);
void bind_TopTools_DataMapOfShapeListOfInteger(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeListOfInteger(py::module &);
void bind_TopTools_Array1OfShape(py::module &);
void bind_TopTools_HArray1OfShape(py::module &);
void bind_TopTools_Array2OfShape(py::module &);
void bind_TopTools_HArray2OfShape(py::module &);
void bind_TopTools_DataMapOfIntegerShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfIntegerShape(py::module &);
void bind_TopTools_DataMapOfShapeReal(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeReal(py::module &);
void bind_TopTools_MutexForShapeProvider(py::module &);
void bind_TopTools_HSequenceOfShape(py::module &);
void bind_TopTools_LocationSet(py::module &);
void bind_TopTools_ShapeSet(py::module &);
void bind_TopTools_Array1OfListOfShape(py::module &);
void bind_TopTools_HArray1OfListOfShape(py::module &);
void bind_TopTools_IndexedDataMapOfShapeAddress(py::module &);
void bind_TopTools(py::module &);
void bind_TopTools_DataMapOfOrientedShapeShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfOrientedShapeShape(py::module &);
void bind_TopTools_DataMapOfShapeSequenceOfShape(py::module &);
void bind_TopTools_DataMapIteratorOfDataMapOfShapeSequenceOfShape(py::module &);
void bind_TopTools_LocationSetPtr(py::module &);
void bind_TopTools_MapOfOrientedShape(py::module &);
void bind_TopTools_MapIteratorOfMapOfOrientedShape(py::module &);

PYBIND11_MODULE(TopTools, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");

bind_TopTools_ListOfShape(mod);
bind_TopTools_ListIteratorOfListOfShape(mod);
bind_TopTools_DataMapOfIntegerListOfShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfIntegerListOfShape(mod);
bind_TopTools_ShapeMapHasher(mod);
bind_TopTools_MapOfShape(mod);
bind_TopTools_MapIteratorOfMapOfShape(mod);
bind_TopTools_IndexedMapOfShape(mod);
bind_TopTools_IndexedDataMapOfShapeListOfShape(mod);
bind_TopTools_DataMapOfShapeListOfShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeListOfShape(mod);
bind_TopTools_DataMapOfShapeShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeShape(mod);
bind_TopTools_DataMapOfShapeBox(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeBox(mod);
bind_TopTools_OrientedShapeMapHasher(mod);
bind_TopTools_IndexedMapOfOrientedShape(mod);
bind_TopTools_DataMapOfShapeInteger(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeInteger(mod);
bind_TopTools_IndexedDataMapOfShapeReal(mod);
bind_TopTools_ListOfListOfShape(mod);
bind_TopTools_ListIteratorOfListOfListOfShape(mod);
bind_TopTools_DataMapOfOrientedShapeInteger(mod);
bind_TopTools_DataMapIteratorOfDataMapOfOrientedShapeInteger(mod);
bind_TopTools_IndexedDataMapOfShapeShape(mod);
bind_TopTools_SequenceOfShape(mod);
bind_TopTools_DataMapOfShapeListOfInteger(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeListOfInteger(mod);
bind_TopTools_Array1OfShape(mod);
bind_TopTools_HArray1OfShape(mod);
bind_TopTools_Array2OfShape(mod);
bind_TopTools_HArray2OfShape(mod);
bind_TopTools_DataMapOfIntegerShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfIntegerShape(mod);
bind_TopTools_DataMapOfShapeReal(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeReal(mod);
bind_TopTools_MutexForShapeProvider(mod);
bind_TopTools_HSequenceOfShape(mod);
bind_TopTools_LocationSet(mod);
bind_TopTools_ShapeSet(mod);
bind_TopTools_Array1OfListOfShape(mod);
bind_TopTools_HArray1OfListOfShape(mod);
bind_TopTools_IndexedDataMapOfShapeAddress(mod);
bind_TopTools(mod);
bind_TopTools_DataMapOfOrientedShapeShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfOrientedShapeShape(mod);
bind_TopTools_DataMapOfShapeSequenceOfShape(mod);
bind_TopTools_DataMapIteratorOfDataMapOfShapeSequenceOfShape(mod);
bind_TopTools_LocationSetPtr(mod);
bind_TopTools_MapOfOrientedShape(mod);
bind_TopTools_MapIteratorOfMapOfOrientedShape(mod);

}
