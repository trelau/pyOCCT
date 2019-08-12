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

void bind_ChFiDS_ErrorStatus(py::module &);
void bind_ChFiDS_ChamfMethod(py::module &);
void bind_ChFiDS_State(py::module &);
void bind_ChFiDS_CircSection(py::module &);
void bind_ChFiDS_SecArray1(py::module &);
void bind_ChFiDS_SecHArray1(py::module &);
void bind_ChFiDS_Map(py::module &);
void bind_ChFiDS_CommonPoint(py::module &);
void bind_ChFiDS_FaceInterference(py::module &);
void bind_ChFiDS_SurfData(py::module &);
void bind_ChFiDS_SequenceOfSurfData(py::module &);
void bind_ChFiDS_HData(py::module &);
void bind_ChFiDS_Stripe(py::module &);
void bind_ChFiDS_ListOfStripe(py::module &);
void bind_ChFiDS_ListIteratorOfListOfStripe(py::module &);
void bind_ChFiDS_IndexedDataMapOfVertexListOfStripe(py::module &);
void bind_ChFiDS_StripeMap(py::module &);
void bind_ChFiDS_Regul(py::module &);
void bind_ChFiDS_Regularities(py::module &);
void bind_ChFiDS_ListIteratorOfRegularities(py::module &);
void bind_ChFiDS_ElSpine(py::module &);
void bind_ChFiDS_HElSpine(py::module &);
void bind_ChFiDS_ListOfHElSpine(py::module &);
void bind_ChFiDS_ListIteratorOfListOfHElSpine(py::module &);
void bind_ChFiDS_Spine(py::module &);
void bind_ChFiDS_ChamfSpine(py::module &);
void bind_ChFiDS_FilSpine(py::module &);
void bind_ChFiDS_SequenceOfSpine(py::module &);
void bind_ChFiDS_StripeArray1(py::module &);

PYBIND11_MODULE(ChFiDS, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Law");

bind_ChFiDS_ErrorStatus(mod);
bind_ChFiDS_ChamfMethod(mod);
bind_ChFiDS_State(mod);
bind_ChFiDS_CircSection(mod);
bind_ChFiDS_SecArray1(mod);
bind_ChFiDS_SecHArray1(mod);
bind_ChFiDS_Map(mod);
bind_ChFiDS_CommonPoint(mod);
bind_ChFiDS_FaceInterference(mod);
bind_ChFiDS_SurfData(mod);
bind_ChFiDS_SequenceOfSurfData(mod);
bind_ChFiDS_HData(mod);
bind_ChFiDS_Stripe(mod);
bind_ChFiDS_ListOfStripe(mod);
bind_ChFiDS_ListIteratorOfListOfStripe(mod);
bind_ChFiDS_IndexedDataMapOfVertexListOfStripe(mod);
bind_ChFiDS_StripeMap(mod);
bind_ChFiDS_Regul(mod);
bind_ChFiDS_Regularities(mod);
bind_ChFiDS_ListIteratorOfRegularities(mod);
bind_ChFiDS_ElSpine(mod);
bind_ChFiDS_HElSpine(mod);
bind_ChFiDS_ListOfHElSpine(mod);
bind_ChFiDS_ListIteratorOfListOfHElSpine(mod);
bind_ChFiDS_Spine(mod);
bind_ChFiDS_ChamfSpine(mod);
bind_ChFiDS_FilSpine(mod);
bind_ChFiDS_SequenceOfSpine(mod);
bind_ChFiDS_StripeArray1(mod);

}
