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

void bind_TNaming_Evolution(py::module &);
void bind_TNaming_NameType(py::module &);
void bind_TNaming_PtrNode(py::module &);
void bind_TNaming_NamedShape(py::module &);
void bind_TNaming_ListOfNamedShape(py::module &);
void bind_TNaming_ListIteratorOfListOfNamedShape(py::module &);
void bind_TNaming_Name(py::module &);
void bind_TNaming_Naming(py::module &);
void bind_TNaming(py::module &);
void bind_TNaming_Builder(py::module &);
void bind_TNaming_CopyShape(py::module &);
void bind_TNaming_PtrRefShape(py::module &);
void bind_TNaming_DataMapOfShapePtrRefShape(py::module &);
void bind_TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape(py::module &);
void bind_TNaming_ShapesSet(py::module &);
void bind_TNaming_DataMapOfShapeShapesSet(py::module &);
void bind_TNaming_DataMapIteratorOfDataMapOfShapeShapesSet(py::module &);
void bind_TNaming_DeltaOnModification(py::module &);
void bind_TNaming_DeltaOnRemoval(py::module &);
void bind_TNaming_Identifier(py::module &);
void bind_TNaming_Iterator(py::module &);
void bind_TNaming_IteratorOnShapesSet(py::module &);
void bind_TNaming_ListOfIndexedDataMapOfShapeListOfShape(py::module &);
void bind_TNaming_ListIteratorOfListOfIndexedDataMapOfShapeListOfShape(py::module &);
void bind_TNaming_ListOfMapOfShape(py::module &);
void bind_TNaming_ListIteratorOfListOfMapOfShape(py::module &);
void bind_TNaming_NamedShapeHasher(py::module &);
void bind_TNaming_MapOfNamedShape(py::module &);
void bind_TNaming_MapIteratorOfMapOfNamedShape(py::module &);
void bind_TNaming_Localizer(py::module &);
void bind_TNaming_NamingTool(py::module &);
void bind_TNaming_MapOfShape(py::module &);
void bind_TNaming_MapIteratorOfMapOfShape(py::module &);
void bind_TNaming_DataMapOfShapeMapOfShape(py::module &);
void bind_TNaming_DataMapIteratorOfDataMapOfShapeMapOfShape(py::module &);
void bind_TNaming_NewShapeIterator(py::module &);
void bind_TNaming_OldShapeIterator(py::module &);
void bind_TNaming_PtrAttribute(py::module &);
void bind_TNaming_RefShape(py::module &);
void bind_TNaming_SameShapeIterator(py::module &);
void bind_TNaming_Scope(py::module &);
void bind_TNaming_Selector(py::module &);
void bind_TNaming_Tool(py::module &);
void bind_TNaming_TranslateTool(py::module &);
void bind_TNaming_Translator(py::module &);
void bind_TNaming_UsedShapes(py::module &);

PYBIND11_MODULE(TNaming, mod) {

py::module::import("OCCT.TDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");

bind_TNaming_Evolution(mod);
bind_TNaming_NameType(mod);
bind_TNaming_PtrNode(mod);
bind_TNaming_NamedShape(mod);
bind_TNaming_ListOfNamedShape(mod);
bind_TNaming_ListIteratorOfListOfNamedShape(mod);
bind_TNaming_Name(mod);
bind_TNaming_Naming(mod);
bind_TNaming(mod);
bind_TNaming_Builder(mod);
bind_TNaming_CopyShape(mod);
bind_TNaming_PtrRefShape(mod);
bind_TNaming_DataMapOfShapePtrRefShape(mod);
bind_TNaming_DataMapIteratorOfDataMapOfShapePtrRefShape(mod);
bind_TNaming_ShapesSet(mod);
bind_TNaming_DataMapOfShapeShapesSet(mod);
bind_TNaming_DataMapIteratorOfDataMapOfShapeShapesSet(mod);
bind_TNaming_DeltaOnModification(mod);
bind_TNaming_DeltaOnRemoval(mod);
bind_TNaming_Identifier(mod);
bind_TNaming_Iterator(mod);
bind_TNaming_IteratorOnShapesSet(mod);
bind_TNaming_ListOfIndexedDataMapOfShapeListOfShape(mod);
bind_TNaming_ListIteratorOfListOfIndexedDataMapOfShapeListOfShape(mod);
bind_TNaming_ListOfMapOfShape(mod);
bind_TNaming_ListIteratorOfListOfMapOfShape(mod);
bind_TNaming_NamedShapeHasher(mod);
bind_TNaming_MapOfNamedShape(mod);
bind_TNaming_MapIteratorOfMapOfNamedShape(mod);
bind_TNaming_Localizer(mod);
bind_TNaming_NamingTool(mod);
bind_TNaming_MapOfShape(mod);
bind_TNaming_MapIteratorOfMapOfShape(mod);
bind_TNaming_DataMapOfShapeMapOfShape(mod);
bind_TNaming_DataMapIteratorOfDataMapOfShapeMapOfShape(mod);
bind_TNaming_NewShapeIterator(mod);
bind_TNaming_OldShapeIterator(mod);
bind_TNaming_PtrAttribute(mod);
bind_TNaming_RefShape(mod);
bind_TNaming_SameShapeIterator(mod);
bind_TNaming_Scope(mod);
bind_TNaming_Selector(mod);
bind_TNaming_Tool(mod);
bind_TNaming_TranslateTool(mod);
bind_TNaming_Translator(mod);
bind_TNaming_UsedShapes(mod);

}
