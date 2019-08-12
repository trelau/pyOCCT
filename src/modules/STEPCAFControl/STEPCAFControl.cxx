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

void bind_STEPCAFControl_ActorWrite(py::module &);
void bind_STEPCAFControl_Controller(py::module &);
void bind_STEPCAFControl_ExternFile(py::module &);
void bind_STEPCAFControl_DataMapOfLabelExternFile(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfLabelExternFile(py::module &);
void bind_STEPCAFControl_DataMapOfLabelShape(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfLabelShape(py::module &);
void bind_STEPCAFControl_DataMapOfPDExternFile(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfPDExternFile(py::module &);
void bind_STEPCAFControl_DataMapOfSDRExternFile(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfSDRExternFile(py::module &);
void bind_STEPCAFControl_DataMapOfShapePD(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfShapePD(py::module &);
void bind_STEPCAFControl_DataMapOfShapeSDR(py::module &);
void bind_STEPCAFControl_DataMapIteratorOfDataMapOfShapeSDR(py::module &);
void bind_STEPCAFControl_GDTProperty(py::module &);
void bind_STEPCAFControl_Reader(py::module &);
void bind_STEPCAFControl_Writer(py::module &);

PYBIND11_MODULE(STEPCAFControl, mod) {

py::module::import("OCCT.STEPControl");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.XSControl");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TDF");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepShape");
py::module::import("OCCT.StepRepr");
py::module::import("OCCT.XCAFDimTolObjects");
py::module::import("OCCT.StepDimTol");
py::module::import("OCCT.StepVisual");
py::module::import("OCCT.TDocStd");
py::module::import("OCCT.XCAFDoc");
py::module::import("OCCT.STEPConstruct");
py::module::import("OCCT.Transfer");
py::module::import("OCCT.StepAP242");
py::module::import("OCCT.gp");
py::module::import("OCCT.MoniTool");

bind_STEPCAFControl_ActorWrite(mod);
bind_STEPCAFControl_Controller(mod);
bind_STEPCAFControl_ExternFile(mod);
bind_STEPCAFControl_DataMapOfLabelExternFile(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfLabelExternFile(mod);
bind_STEPCAFControl_DataMapOfLabelShape(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfLabelShape(mod);
bind_STEPCAFControl_DataMapOfPDExternFile(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfPDExternFile(mod);
bind_STEPCAFControl_DataMapOfSDRExternFile(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfSDRExternFile(mod);
bind_STEPCAFControl_DataMapOfShapePD(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfShapePD(mod);
bind_STEPCAFControl_DataMapOfShapeSDR(mod);
bind_STEPCAFControl_DataMapIteratorOfDataMapOfShapeSDR(mod);
bind_STEPCAFControl_GDTProperty(mod);
bind_STEPCAFControl_Reader(mod);
bind_STEPCAFControl_Writer(mod);

}
