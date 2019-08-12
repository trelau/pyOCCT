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
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <ShapeAnalysis_WireOrder.hxx>

void bind_ShapeAnalysis_WireOrder(py::module &mod){

py::class_<ShapeAnalysis_WireOrder, std::unique_ptr<ShapeAnalysis_WireOrder, Deleter<ShapeAnalysis_WireOrder>>> cls_ShapeAnalysis_WireOrder(mod, "ShapeAnalysis_WireOrder", "This class is intended to control and, if possible, redefine the order of a list of edges which define a wire Edges are not given directly, but as their bounds (start,end)");

// Constructors
cls_ShapeAnalysis_WireOrder.def(py::init<>());
cls_ShapeAnalysis_WireOrder.def(py::init<const Standard_Boolean, const Standard_Real>(), py::arg("mode3d"), py::arg("tol"));

// Fields

// Methods
// cls_ShapeAnalysis_WireOrder.def_static("operator new_", (void * (*)(size_t)) &ShapeAnalysis_WireOrder::operator new, "None", py::arg("theSize"));
// cls_ShapeAnalysis_WireOrder.def_static("operator delete_", (void (*)(void *)) &ShapeAnalysis_WireOrder::operator delete, "None", py::arg("theAddress"));
// cls_ShapeAnalysis_WireOrder.def_static("operator new[]_", (void * (*)(size_t)) &ShapeAnalysis_WireOrder::operator new[], "None", py::arg("theSize"));
// cls_ShapeAnalysis_WireOrder.def_static("operator delete[]_", (void (*)(void *)) &ShapeAnalysis_WireOrder::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeAnalysis_WireOrder.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeAnalysis_WireOrder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeAnalysis_WireOrder.def_static("operator delete_", (void (*)(void *, void *)) &ShapeAnalysis_WireOrder::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeAnalysis_WireOrder.def("SetMode", (void (ShapeAnalysis_WireOrder::*)(const Standard_Boolean, const Standard_Real)) &ShapeAnalysis_WireOrder::SetMode, "Sets new values. Clears the connexion list If <mode3d> changes, also clears the edge list (else, doesnt)", py::arg("mode3d"), py::arg("tol"));
cls_ShapeAnalysis_WireOrder.def("Tolerance", (Standard_Real (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::Tolerance, "Returns the working tolerance");
cls_ShapeAnalysis_WireOrder.def("Clear", (void (ShapeAnalysis_WireOrder::*)()) &ShapeAnalysis_WireOrder::Clear, "Clears the list of edges, but not mode and tol");
cls_ShapeAnalysis_WireOrder.def("Add", (void (ShapeAnalysis_WireOrder::*)(const gp_XYZ &, const gp_XYZ &)) &ShapeAnalysis_WireOrder::Add, "Adds a couple of points 3D (start,end)", py::arg("start3d"), py::arg("end3d"));
cls_ShapeAnalysis_WireOrder.def("Add", (void (ShapeAnalysis_WireOrder::*)(const gp_XY &, const gp_XY &)) &ShapeAnalysis_WireOrder::Add, "Adds a couple of points 2D (start,end)", py::arg("start2d"), py::arg("end2d"));
cls_ShapeAnalysis_WireOrder.def("NbEdges", (Standard_Integer (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::NbEdges, "Returns the count of added couples of points (one per edges)");
cls_ShapeAnalysis_WireOrder.def("KeepLoopsMode", (Standard_Boolean & (ShapeAnalysis_WireOrder::*)()) &ShapeAnalysis_WireOrder::KeepLoopsMode, "If this mode is True method perform does not sort edges of different loops. The resulting order is first loop, second one etc...");
cls_ShapeAnalysis_WireOrder.def("Perform", [](ShapeAnalysis_WireOrder &self) -> void { return self.Perform(); });
cls_ShapeAnalysis_WireOrder.def("Perform", (void (ShapeAnalysis_WireOrder::*)(const Standard_Boolean)) &ShapeAnalysis_WireOrder::Perform, "Computes the better order If <closed> is True (D) considers also closure Optimised if the couples were already in order The criterium is : two couples in order if distance between end-prec and start-cur is less then starting tolerance <tol> Else, the smallest distance is reached Gap corresponds to a smallest distance greater than <tol>", py::arg("closed"));
cls_ShapeAnalysis_WireOrder.def("IsDone", (Standard_Boolean (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::IsDone, "Tells if Perform has been done Else, the following methods returns original values");
cls_ShapeAnalysis_WireOrder.def("Status", (Standard_Integer (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::Status, "Returns the status of the order (0 if not done) : 0 : all edges are direct and in sequence 1 : all edges are direct but some are not in sequence 2 : in addition, unresolved gaps remain -1 : some edges are reversed, but no gap remain -2 : some edges are reversed and some gaps remain -10 : COULD NOT BE RESOLVED, Failure on Reorder gap : regarding starting <tol>");
cls_ShapeAnalysis_WireOrder.def("Ordered", (Standard_Integer (ShapeAnalysis_WireOrder::*)(const Standard_Integer) const) &ShapeAnalysis_WireOrder::Ordered, "Returns the number of original edge which correspond to the newly ordered number <n> Warning : the returned value is NEGATIVE if edge should be reversed", py::arg("n"));
cls_ShapeAnalysis_WireOrder.def("XYZ", (void (ShapeAnalysis_WireOrder::*)(const Standard_Integer, gp_XYZ &, gp_XYZ &) const) &ShapeAnalysis_WireOrder::XYZ, "Returns the values of the couple <num>, as 3D values", py::arg("num"), py::arg("start3d"), py::arg("end3d"));
cls_ShapeAnalysis_WireOrder.def("XY", (void (ShapeAnalysis_WireOrder::*)(const Standard_Integer, gp_XY &, gp_XY &) const) &ShapeAnalysis_WireOrder::XY, "Returns the values of the couple <num>, as 2D values", py::arg("num"), py::arg("start2d"), py::arg("end2d"));
cls_ShapeAnalysis_WireOrder.def("Gap", [](ShapeAnalysis_WireOrder &self) -> Standard_Real { return self.Gap(); });
cls_ShapeAnalysis_WireOrder.def("Gap", (Standard_Real (ShapeAnalysis_WireOrder::*)(const Standard_Integer) const) &ShapeAnalysis_WireOrder::Gap, "Returns the gap between a couple and its preceeding <num> is considered ordered If <num> = 0 (D), returns the greatest gap found", py::arg("num"));
cls_ShapeAnalysis_WireOrder.def("SetChains", (void (ShapeAnalysis_WireOrder::*)(const Standard_Real)) &ShapeAnalysis_WireOrder::SetChains, "Determines the chains inside which successive edges have a gap less than a given value. Queried by NbChains and Chain", py::arg("gap"));
cls_ShapeAnalysis_WireOrder.def("NbChains", (Standard_Integer (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::NbChains, "Returns the count of computed chains");
cls_ShapeAnalysis_WireOrder.def("Chain", [](ShapeAnalysis_WireOrder &self, const Standard_Integer num, Standard_Integer & n1, Standard_Integer & n2){ self.Chain(num, n1, n2); return std::tuple<Standard_Integer &, Standard_Integer &>(n1, n2); }, "Returns, for the chain n0 num, starting and ending numbers of edges. In the list of ordered edges (see Ordered for originals)", py::arg("num"), py::arg("n1"), py::arg("n2"));
cls_ShapeAnalysis_WireOrder.def("SetCouples", (void (ShapeAnalysis_WireOrder::*)(const Standard_Real)) &ShapeAnalysis_WireOrder::SetCouples, "Determines the couples of edges for which end and start fit inside a given gap. Queried by NbCouples and Couple", py::arg("gap"));
cls_ShapeAnalysis_WireOrder.def("NbCouples", (Standard_Integer (ShapeAnalysis_WireOrder::*)() const) &ShapeAnalysis_WireOrder::NbCouples, "Returns the count of computed couples");
cls_ShapeAnalysis_WireOrder.def("Couple", [](ShapeAnalysis_WireOrder &self, const Standard_Integer num, Standard_Integer & n1, Standard_Integer & n2){ self.Couple(num, n1, n2); return std::tuple<Standard_Integer &, Standard_Integer &>(n1, n2); }, "Returns, for the couple n0 num, the two implied edges In the list of ordered edges", py::arg("num"), py::arg("n1"), py::arg("n2"));

// Enums

}