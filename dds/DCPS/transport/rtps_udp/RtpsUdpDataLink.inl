/*
 *
 *
 * Distributed under the OpenDDS License.
 * See: http://www.opendds.org/license.html
 */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL

namespace OpenDDS {
namespace DCPS {



ACE_INLINE ACE_Reactor*
RtpsUdpDataLink::get_reactor()
{
  if (!reactor_task_) return 0;
  return reactor_task_->get_reactor();
}

ACE_INLINE bool
RtpsUdpDataLink::reactor_is_shut_down()
{
  if (!reactor_task_) return true;
  return reactor_task_->is_shut_down();
}

ACE_INLINE ACE_SOCK_Dgram&
RtpsUdpDataLink::unicast_socket()
{
  return unicast_socket_;
}

ACE_INLINE ACE_SOCK_Dgram_Mcast&
RtpsUdpDataLink::multicast_socket()
{
  return multicast_socket_;
}

ACE_INLINE void
RtpsUdpDataLink::release_remote_i(const RepoId& remote_id)
{
  locators_.erase(remote_id);
}

ACE_INLINE DDS::Security::ParticipantCryptoHandle
RtpsUdpDataLink::local_crypto_handle() const
{
  return local_crypto_handle_;
}

ACE_INLINE void
RtpsUdpDataLink::local_crypto_handle(DDS::Security::ParticipantCryptoHandle h)
{
  local_crypto_handle_ = h;
}

ACE_INLINE DDS::Security::ParticipantCryptoHandle
RtpsUdpDataLink::peer_crypto_handle(const RepoId& peer) const
{
  typedef OPENDDS_MAP_CMP(RepoId, DDS::Security::ParticipantCryptoHandle,
                          GUID_tKeyLessThan)::const_iterator iter_t;
  const iter_t it = peer_crypto_handles_.find(peer);
  return (it == peer_crypto_handles_.end()) ? DDS::HANDLE_NIL : it->second;
}

} // namespace DCPS
} // namespace OpenDDS

OPENDDS_END_VERSIONED_NAMESPACE_DECL
