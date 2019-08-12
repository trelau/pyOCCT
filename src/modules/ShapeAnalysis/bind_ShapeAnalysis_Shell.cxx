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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Compound.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <ShapeAnalysis_Shell.hxx>

void bind_ShapeAnalysis_Shell(py::module &mod){

py::class_<ShapeAnalysis_Shell, std::unique_ptr<ShapeAnalysis_Shell, Deleter<ShapeAnalysis_Shell>>> cls_ShapeAnalysis_Shell(mod, "ShapeAnalysis_Shell", "This class provides operators to analyze edges orientation in the shell.");

// Constructors

// Fields

// Methods
// cls_ShapeAnalysis_Shell.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_Shell::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_Shell.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_Shell::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Shell.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_Shell::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_Shell.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_Shell::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_Shell.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_Shell::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_Shell.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_Shell::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_Shell.def("Clear", (void (ShapeAnalysis_Shell::*)()) &ShapeAnalysis_Shell::Clear, "Clears data about loaded shells and performed checks");
cls_ShapeAnalysis_Shell.def("LoadShells", (void (ShapeAnalysis_Shell::*)(const TopoDS_Shape &)) &ShapeAnalysis_Shell::LoadShells, "Adds shells contained in the <shape> to the list of loaded shells", py::arg("shape"));
cls_ShapeAnalysis_Shell.def("CheckOrientedShells", [](ShapeAnalysis_Shell &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.CheckOrientedShells(a0); });
cls_ShapeAnalysis_Shell.def("CheckOrientedShells", [](ShapeAnalysis_Shell &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.CheckOrientedShells(a0, a1); });
cls_ShapeAnalysis_Shell.def("CheckOrientedShells", (Standard_Boolean (ShapeAnalysis_Shell::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &ShapeAnalysis_Shell::CheckOrientedShells, "Checks if shells fulfill orientation condition, i.e. if each edge is, either present once (free edge) or twice (connected edge) but with different orientations (FORWARD/REVERSED) Edges which do not fulfill these conditions are bad", py::arg("shape"), py::arg("alsofree"), py::arg("checkinternaledges"));
cls_ShapeAnalysis_Shell.def("IsLoaded", (Standard_Boolean (ShapeAnalysis_Shell::*)(const TopoDS_Shape &) const) &ShapeAnalysis_Shell::IsLoaded, "Tells if a shape is loaded (only shells are checked)", py::arg("shape"));
cls_ShapeAnalysis_Shell.def("NbLoaded", (Standard_Integer (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::NbLoaded, "Returns the actual number of loaded shapes (i.e. shells)");
cls_ShapeAnalysis_Shell.def("Loaded", (TopoDS_Shape (ShapeAnalysis_Shell::*)(const Standard_Integer) const) &ShapeAnalysis_Shell::Loaded, "Returns a loaded shape specified by its rank number. Returns null shape if <num> is out of range", py::arg("num"));
cls_ShapeAnalysis_Shell.def("HasBadEdges", (Standard_Boolean (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::HasBadEdges, "Tells if at least one edge is recorded as bad");
cls_ShapeAnalysis_Shell.def("BadEdges", (TopoDS_Compound (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::BadEdges, "Returns the list of bad edges as a Compound It is empty (not null) if no edge are recorded as bad");
cls_ShapeAnalysis_Shell.def("HasFreeEdges", (Standard_Boolean (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::HasFreeEdges, "Tells if at least one edge is recorded as free (not connected)");
cls_ShapeAnalysis_Shell.def("FreeEdges", (TopoDS_Compound (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::FreeEdges, "Returns the list of free (not connected) edges as a Compound It is empty (not null) if no edge are recorded as free");
cls_ShapeAnalysis_Shell.def("HasConnectedEdges", (Standard_Boolean (ShapeAnalysis_Shell::*)() const) &ShapeAnalysis_Shell::HasConnectedEdges, "Tells if at least one edge is connected (shared twice or more)");

// Enums

}