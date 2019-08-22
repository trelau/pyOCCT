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
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <TopoDS_Face.hxx>
#include <TopClass_SolidExplorer.hxx>

void bind_TopClass_SolidExplorer(py::module &mod){

py::class_<TopClass_SolidExplorer> cls_TopClass_SolidExplorer(mod, "TopClass_SolidExplorer", "Provide an exploration of a BRep Shape for the classification. Defines the description of a solid for the SolidClassifier.");

// Fields

// Methods
// cls_TopClass_SolidExplorer.def_static("operator new_", (void * (*)(size_t)) &TopClass_SolidExplorer::operator new, "None", py::arg("theSize"));
// cls_TopClass_SolidExplorer.def_static("operator delete_", (void (*)(void *)) &TopClass_SolidExplorer::operator delete, "None", py::arg("theAddress"));
// cls_TopClass_SolidExplorer.def_static("operator new[]_", (void * (*)(size_t)) &TopClass_SolidExplorer::operator new[], "None", py::arg("theSize"));
// cls_TopClass_SolidExplorer.def_static("operator delete[]_", (void (*)(void *)) &TopClass_SolidExplorer::operator delete[], "None", py::arg("theAddress"));
// cls_TopClass_SolidExplorer.def_static("operator new_", (void * (*)(size_t, void *)) &TopClass_SolidExplorer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopClass_SolidExplorer.def_static("operator delete_", (void (*)(void *, void *)) &TopClass_SolidExplorer::operator delete, "None", py::arg(""), py::arg(""));
cls_TopClass_SolidExplorer.def("Reject", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Pnt &) const) &TopClass_SolidExplorer::Reject, "Should return True if the point is outside a bounding volume of the shape.", py::arg("P"));
cls_TopClass_SolidExplorer.def("Segment", [](TopClass_SolidExplorer &self, const gp_Pnt & P, gp_Lin & L, Standard_Real & Par){ self.Segment(P, L, Par); return Par; }, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_TopClass_SolidExplorer.def("OtherSegment", [](TopClass_SolidExplorer &self, const gp_Pnt & P, gp_Lin & L, Standard_Real & Par){ self.OtherSegment(P, L, Par); return Par; }, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
cls_TopClass_SolidExplorer.def("InitShell", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::InitShell, "Starts an exploration of the shells.");
cls_TopClass_SolidExplorer.def("MoreShells", (Standard_Boolean (TopClass_SolidExplorer::*)() const) &TopClass_SolidExplorer::MoreShells, "Returns True if there is a current shell.");
cls_TopClass_SolidExplorer.def("NextShell", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::NextShell, "Sets the explorer to the next shell and returns False if there are no more wires.");
cls_TopClass_SolidExplorer.def("RejectShell", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Lin &, const Standard_Real) const) &TopClass_SolidExplorer::RejectShell, "Returns True if the shell bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
cls_TopClass_SolidExplorer.def("InitFace", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::InitFace, "Starts an exploration of the faces.");
cls_TopClass_SolidExplorer.def("MoreFaces", (Standard_Boolean (TopClass_SolidExplorer::*)() const) &TopClass_SolidExplorer::MoreFaces, "Returns True if there is a current face.");
cls_TopClass_SolidExplorer.def("NextFace", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::NextFace, "Sets the explorer to the next face and returns False if there are no more wires.");
cls_TopClass_SolidExplorer.def("CurrentFace", (TopoDS_Face (TopClass_SolidExplorer::*)() const) &TopClass_SolidExplorer::CurrentFace, "Returns the current face.");
cls_TopClass_SolidExplorer.def("RejectFace", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Lin &, const Standard_Real) const) &TopClass_SolidExplorer::RejectFace, "Returns True if the face bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));

// Enums

}