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

void bind_BOPTools_ConnexityBlock(py::module &);
void bind_BOPTools_ListOfConnexityBlock(py::module &);
void bind_BOPTools_ListIteratorOfListOfConnexityBlock(py::module &);
void bind_BOPTools_CoupleOfShape(py::module &);
void bind_BOPTools_ListOfCoupleOfShape(py::module &);
void bind_BOPTools_ListIteratorOfListOfCoupleOfShape(py::module &);
void bind_BOPTools_AlgoTools(py::module &);
void bind_BOPTools_AlgoTools2D(py::module &);
void bind_BOPTools_AlgoTools3D(py::module &);
void bind_BOPTools_BoxBndTree(py::module &);
void bind_BOPTools_BoxBndTreeSelector(py::module &);
void bind_BOPTools_Set(py::module &);
void bind_BOPTools_SetMapHasher(py::module &);
void bind_BOPTools_IndexedDataMapOfSetShape(py::module &);
void bind_BOPTools_MapOfSet(py::module &);
void bind_BOPTools_MapIteratorOfMapOfSet(py::module &);

PYBIND11_MODULE(BOPTools, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.gp");
py::module::import("OCCT.Precision");
py::module::import("OCCT.IntTools");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.Message");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColStd");

bind_BOPTools_ConnexityBlock(mod);
bind_BOPTools_ListOfConnexityBlock(mod);
bind_BOPTools_ListIteratorOfListOfConnexityBlock(mod);
bind_BOPTools_CoupleOfShape(mod);
bind_BOPTools_ListOfCoupleOfShape(mod);
bind_BOPTools_ListIteratorOfListOfCoupleOfShape(mod);
bind_BOPTools_AlgoTools(mod);
bind_BOPTools_AlgoTools2D(mod);
bind_BOPTools_AlgoTools3D(mod);
bind_BOPTools_BoxBndTree(mod);
bind_BOPTools_BoxBndTreeSelector(mod);
bind_BOPTools_Set(mod);
bind_BOPTools_SetMapHasher(mod);
bind_BOPTools_IndexedDataMapOfSetShape(mod);
bind_BOPTools_MapOfSet(mod);
bind_BOPTools_MapIteratorOfMapOfSet(mod);

}
