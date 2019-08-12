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

void bind_TDocStd_Application(py::module &);
void bind_TDocStd_XLinkPtr(py::module &);
void bind_TDocStd_XLink(py::module &);
void bind_TDocStd(py::module &);
void bind_TDocStd_Document(py::module &);
void bind_TDocStd_SequenceOfDocument(py::module &);
void bind_TDocStd_ApplicationDelta(py::module &);
void bind_TDocStd_CompoundDelta(py::module &);
void bind_TDocStd_Context(py::module &);
void bind_TDocStd_LabelIDMapDataMap(py::module &);
void bind_TDocStd_DataMapIteratorOfLabelIDMapDataMap(py::module &);
void bind_TDocStd_Modified(py::module &);
void bind_TDocStd_SequenceOfApplicationDelta(py::module &);
void bind_TDocStd_MultiTransactionManager(py::module &);
void bind_TDocStd_Owner(py::module &);
void bind_TDocStd_PathParser(py::module &);
void bind_TDocStd_XLinkIterator(py::module &);
void bind_TDocStd_XLinkRoot(py::module &);
void bind_TDocStd_XLinkTool(py::module &);

PYBIND11_MODULE(TDocStd, mod) {

py::module::import("OCCT.CDF");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Message");
py::module::import("OCCT.Resource");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.PCDM");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TDF");
py::module::import("OCCT.CDM");
py::module::import("OCCT.NCollection");

bind_TDocStd_Application(mod);
bind_TDocStd_XLinkPtr(mod);
bind_TDocStd_XLink(mod);
bind_TDocStd(mod);
bind_TDocStd_Document(mod);
bind_TDocStd_SequenceOfDocument(mod);
bind_TDocStd_ApplicationDelta(mod);
bind_TDocStd_CompoundDelta(mod);
bind_TDocStd_Context(mod);
bind_TDocStd_LabelIDMapDataMap(mod);
bind_TDocStd_DataMapIteratorOfLabelIDMapDataMap(mod);
bind_TDocStd_Modified(mod);
bind_TDocStd_SequenceOfApplicationDelta(mod);
bind_TDocStd_MultiTransactionManager(mod);
bind_TDocStd_Owner(mod);
bind_TDocStd_PathParser(mod);
bind_TDocStd_XLinkIterator(mod);
bind_TDocStd_XLinkRoot(mod);
bind_TDocStd_XLinkTool(mod);

}
